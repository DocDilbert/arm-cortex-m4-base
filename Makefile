# Project name
PROJECT = arm-cortex-m4-base

# Additional make flags.
# - Disable built-in rules. This speeds up the compilation
MAKEFLAGS += --no-builtin-rules

# Optimization related flags supplied to the compiler
OPT_FLAGS = -O0

# Debug related flags supplied to the compiler
DEBUG_FLAGS = -gdwarf-2 -g3

# Compiler options passed to gcc and c++
COMPILER_OPTIONS = -fno-exceptions
 
# C-Standard - Enable c11 support
C_STD_FLAGS = -std=c11

# Linker script
LD_SCRIPT = hal/linker.ld

# Source files          
SRC_FILES = main.cpp \
			syscalls.c \
			systick.c \
			utils.c \
			hal/reset.c \
			hal/gpio.c \
			hal/target/system_mb9b560r.c
			
# Include directories
INC_DIRS = 	. \
			hal \
			hal/cmsis \
			hal/target
			   
# Object directory
OBJ_DIR = objs

# Toolchain prefix
TC_PREFIX = arm-none-eabi-

# Tool definition
LD  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)gcc
CC  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)gcc
CPP = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)c++
AS  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)as
OBJDUMP = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)objdump
DOXYGEN = doxygen

TARGET = $(PROJECT)

INC_DIRS_FLAGS = $(patsubst %,-I %, $(INC_DIRS))

# Filter .c files in SRC_FILES LIST 
CC_SRC_FILES = $(filter %.c, $(SRC_FILES))

# Filter .cpp files in SRC_FILES LIST
CPP_SRC_FILES = $(filter %.cpp, $(SRC_FILES))

# Generate object lists 
CC_OBJS  = $(patsubst %.c, $(OBJ_DIR)/%.o,  $(notdir $(CC_SRC_FILES)))
CPP_OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o,  $(notdir $(CPP_SRC_FILES)))

DEPS = $(CC_OBJS:.o=.d) $(CPP_OBJS:.o=.d) 

# Define search path
VPATH = $(sort $(dir $(SRC_FILES)))

##############################################################
# Custom options for cortex-m and cortex-r processors
############################################################## 
CORTEX_M0PLUS_CC_FLAGS  = -mthumb -mcpu=cortex-m0plus
CORTEX_M0PLUS_LIB_PATH  = $(GCC_LIB)armv6-m
CORTEX_M0_CC_FLAGS      = -mthumb -mcpu=cortex-m0
CORTEX_M0_LIB_PATH      = $(GCC_LIB)armv6-m
CORTEX_M1_CC_FLAGS      = -mthumb -mcpu=cortex-m1
CORTEX_M1_LIB_PATH      = $(GCC_LIB)armv6-m
CORTEX_M3_CC_FLAGS      = -mthumb -mcpu=cortex-m3
CORTEX_M3_LIB_PATH      = $(GCC_LIB)armv7-m
CORTEX_M4_NOFP_CC_FLAGS = -mthumb -mcpu=cortex-m4
CORTEX_M4_NOFP_LIB_PATH = $(GCC_LIB)armv7e-m
CORTEX_M4_SWFP_CC_FLAGS = -mthumb -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16
CORTEX_M4_SWFP_LIB_PATH = $(GCC_LIB)armv7e-m/softfp
CORTEX_M4_HWFP_CC_FLAGS = -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
CORTEX_M4_HWFP_LIB_PATH = $(GCC_LIB)armv7e-m/fpu
CORTEX_R4_NOFP_CC_FLAGS = -mthumb -march=armv7-r
CORTEX_R4_NOFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb
CORTEX_R4_SWFP_CC_FLAGS = -mthumb -march=armv7-r -mfloat-abi=softfp -mfloat-abi=softfp -mfpu=vfpv3-d16
CORTEX_R4_SWFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb/softfp
CORTEX_R4_HWFP_CC_FLAGS = -mthumb -march=armv7-r -mfloat-abi=softfp -mfloat-abi=hard -mfpu=vfpv3-d16
CORTEX_R4_HWFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb/fpu
CORTEX_R5_NOFP_CC_FLAGS = -mthumb -march=armv7-r
CORTEX_R5_NOFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb
CORTEX_R5_SWFP_CC_FLAGS = -mthumb -march=armv7-r -mfloat-abi=softfp -mfloat-abi=softfp -mfpu=vfpv3-d16
CORTEX_R5_SWFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb/softfp
CORTEX_R5_HWFP_CC_FLAGS = -mthumb -march=armv7-r -mfloat-abi=softfp -mfloat-abi=hard -mfpu=vfpv3-d16
CORTEX_R5_HWFP_LIB_PATH = $(GCC_LIB)armv7-r/thumb/fpu
MCU_CC_FLAGS = $(CORTEX_M4_HWFP_CC_FLAGS)

##############################################################
# Grouping of all compiler flags
##############################################################

CC_FLAGS  = $(C_STD_FLAGS) $(OPT_FLAGS) $(COMPILER_OPTIONS) $(MCU_CC_FLAGS) $(INC_DIRS_FLAGS) $(DEBUG_FLAGS) 
CC_FLAGS += -MP -MMD

CPP_FLAGS  = $(OPT_FLAGS) $(MCU_CC_FLAGS) $(COMPILER_OPTIONS) $(INC_DIRS_FLAGS) $(DEBUG_FLAGS)
CPP_FLAGS += -fno-rtti # Disable runtime type information 
CPP_FLAGS += -MP -MMD 

##############################################################
# Grouping of all linker flags
##############################################################
LD_FLAGS = $(OPT_FLAGS) $(MCU_CC_FLAGS)  -T $(LD_SCRIPT) 

# --gc-sections - Enable garbage collection of unused input sections. 
# --cref - Output a cross reference table in map file
LD_FLAGS += -Wl,-Map=$(OBJ_DIR)/$(TARGET).map,--cref,--gc-sections

# All phony targets
.PHONY: all info clean doc

all: $(TARGET).elf              

$(TARGET).elf : $(OBJ_DIR)/boot.o $(CC_OBJS) $(CPP_OBJS) hal/linker.ld
	@echo 
	@echo "Linking:"
	$(LD) $(LD_FLAGS) $(OBJ_DIR)/boot.o $(CC_OBJS) $(CPP_OBJS) -o $(TARGET).elf

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(OBJ_DIR)/boot.o: hal/boot.s | $(OBJ_DIR)
	$(AS) $(MCU_CC_FLAGS) $(DEBUG_FLAGS) -c hal/boot.s -o $(OBJ_DIR)/boot.o
 
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
info:
	arm-none-eabi-size --format=SysV -x $(TARGET).elf

doc:
	$(DOXYGEN) doxygen.config
	
clean:
	rm -f $(TARGET).elf
	rm -rf $(OBJ_DIR)
	rm -rf ./doc

# Include auto dependencies
-include $(DEPS)

