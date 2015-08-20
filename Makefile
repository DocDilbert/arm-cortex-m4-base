# Disable make built-in rules. This speeds up the compilation
MAKEFLAGS += --no-builtin-rules

# Name of the output elf file
ELF_NAME = fm4.elf

# Optimization related flags supplied to the compiler
OPT_FLAGS = -O0

# Debug related flags supplied to the compiler
DEBUG_FLAGS = -gdwarf-2 -g3

# Source files          
SRC_FILES = ./main.c \
			./syscalls.c \
			./irq.c \
			./baseinit.c \
			./hal/hw_gpio.c \
			./hal/target/system_mb9b560r.c
			
# Include directories
INC_DIRS = 	./hal\
			./hal/target
			   
# Object directory
OBJ_DIR = ./objs

# Toolchain prefix
TC_PREFIX=arm-none-eabi-

# Tool definition
LD=$(TC_PREFIX)ld
CC=$(TC_PREFIX)gcc
AS=$(TC_PREFIX)as
OBJDUMP=$(TC_PREFIX)objdump
DOXYGEN=doxygen

# Custom options for cortex-m and cortex-r processors 
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

INC_DIRS_FLAGS = -I. $(patsubst %,-I%, $(INC_DIRS))

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
DEPS = $(OBJS:.o=.d)
VPATH = $(sort $(dir $(SRC_FILES)))

# Grouping of all compiler flags
CFLAGS = $(OPT_FLAGS) $(MCU_CC_FLAGS) $(INC_DIRS_FLAGS) $(DEBUG_FLAGS) -MP -MMD

# All phony targets
.PHONY: all info clean doc

all: $(ELF_NAME)              

$(ELF_NAME): $(OBJ_DIR)/boot.o $(OBJS) hal/linker.ld
	@echo 
	@echo "Linking:"
	$(LD) -T hal/linker.ld $(OBJ_DIR)/boot.o $(OBJS) -o $(ELF_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR)/boot.o: hal/boot.s | $(OBJ_DIR)
	$(AS) $(MCU_CC_FLAGS) -g hal/boot.s -o $(OBJ_DIR)/boot.o
 
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
info:
	$(OBJDUMP) -h $(ELF_NAME)

doc:
	$(DOXYGEN) doxygen.config
	
clean:
	rm -f $(ELF_NAME)
	rm -rf $(OBJ_DIR)
	rm -rf ./doc

# Include auto dependencies
-include $(DEPS)

