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
COMPILER_OPTIONS  = -fno-exceptions
COMPILER_OPTIONS += #-ffunction-sections # Place each function item into its own section in the output file
COMPILER_OPTIONS += #-fdata-sections # Place each data item into its own section in the output file
 
# C specific compiler flags
C_USER_FLAGS = -std=c11 # enable c11 standard

# C++ specific compiler options
CXX_USER_FLAGS = -fno-rtti # Disable runtime type information 

# Linker script
LD_SCRIPT = src/hal/linker.ld

# Source files          
SRCS =  src/pre_sections.s \
		src/main.cpp \
		src/systick.cpp \
		src/utils.cpp \
		src/reset.cpp \
		src/faults.cpp \
		src/syscalls/general.c \
		src/syscalls/sbrk.c \
		src/hal/isr_vectors.s \
		src/hal/gpio.cpp \
		ext/cypress/mb9bf56xr/system_mb9b560r.c
			
# Include directories
INC_DIRS = 	./src \
			./src/hal \
			./ext/cmsis \
			./ext/cypress/mb9bf56xr
			   
# Object directory
OBJ_DIR = objs

# Toolchain prefix
# It is very important to specify a bare metal compiler here
TC_PREFIX = arm-none-eabi-

# Tool definition
LD  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)c++
CC  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)gcc
CPP = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)c++
AS  = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)as
SIZE = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)size
OBJDUMP = $(ARM_GCC_PATH)/bin/$(TC_PREFIX)objdump
DOXYGEN = doxygen

TARGET = $(PROJECT).elf

INC_DIRS_FLAGS = $(patsubst %,-I%, $(INC_DIRS))

# Filter .c files in SRCS list 
C_SRCS = $(strip $(filter %.c, $(SRCS)))

# Filter .cpp files in SRCS list
CXX_SRCS = $(strip $(filter %.cpp, $(SRCS)))

# Filter .s files in SRCS list
S_SRCS = $(strip $(filter %.s, $(SRCS)))

# Generate object lists 
C_OBJS  = $(strip $(patsubst %.c, $(OBJ_DIR)/%.o,  $(notdir $(C_SRCS))))
CXX_OBJS = $(strip $(patsubst %.cpp, $(OBJ_DIR)/%.o,  $(notdir $(CXX_SRCS))))
S_OBJS = $(strip $(patsubst %.s, $(OBJ_DIR)/%.o,  $(notdir $(S_SRCS))))

DEPS = $(C_OBJS:.o=.d) $(CXX_OBJS:.o=.d) 

# Define search path
VPATH = $(sort $(dir $(SRCS)))

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
C_FLAGS := $(OPT_FLAGS) $(COMPILER_OPTIONS) $(MCU_CC_FLAGS) $(INC_DIRS_FLAGS) $(DEBUG_FLAGS)
C_FLAGS += -MP -MMD $(C_USER_FLAGS) 
C_FLAGS :=  $(strip $(C_FLAGS))

CXX_FLAGS := $(OPT_FLAGS) $(COMPILER_OPTIONS) $(MCU_CC_FLAGS) $(INC_DIRS_FLAGS) $(DEBUG_FLAGS)
CXX_FLAGS += -MP -MMD $(CXX_USER_FLAGS)
CXX_FLAGS := $(strip $(CXX_FLAGS))

AS_FLAGS :=  $(MCU_CC_FLAGS) $(DEBUG_FLAGS)
AS_FLAGS := $(strip $(AS_FLAGS))

##############################################################
# Grouping of all linker flags
##############################################################
LD_FLAGS := --specs=nano.specs # Compile with newlibc-nano and libstdc++-nano. This greatly reduces the code size.
LD_FLAGS += $(CXX_USER_FLAGS) $(OPT_FLAGS) $(COMPILER_OPTIONS)  $(MCU_CC_FLAGS) -T $(LD_SCRIPT)
# --gc-sections - Enable garbage collection of unused input sections. 
# --cref - Output a cross reference table in map file
LD_FLAGS += -Wl,-Map=$(OBJ_DIR)/$(TARGET).map,--cref,--gc-sections
LD_FLAGS := $(strip $(LD_FLAGS))

# All phony targets
.PHONY: all info clean cleandoc doc

all: $(TARGET)              

$(TARGET) : $(S_OBJS) $(C_OBJS) $(CXX_OBJS) $(LD_SCRIPT)
	@echo 
	@echo "Linking:"
	$(LD) $(LD_FLAGS) $(S_OBJS) $(C_OBJS) $(CXX_OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) $(CXX_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(AS) $(AS_FLAGS) -c $< -o $@
 
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
info: $(TARGET)
	@$(SIZE) --format=sysv -x $(TARGET)

doc: doc/cmsis	
	@$(DOXYGEN) doc/base.config

# This is intentionally not a phony target. When the directory not exists the documentation
# is generated. If it exists, nothing is generated.
doc/cmsis:	
	@$(DOXYGEN) doc/cmsis.config
	
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

cleandoc:
	rm -rf ./doc/base
	rm -rf ./doc/cmsis


# Include auto dependencies
-include $(DEPS)

