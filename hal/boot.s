.syntax unified
.thumb

.section .isr_vector,"xa"
.globl  _isr_vector_m
.type   _isr_vector_m, %object
_isr_vector_m:
	.align 2 // make sure the alignment is correct
    .long stack_top
    .long ResetTramp         // Reset
    .long Hang               // NMI
    .long Hang               // Hard Fault
    .long Hang               // MPU Fault
    .long Hang               // Bus Fault
    .long Hang               // Usage Fault
    .long Hang               // Reserved
    .long Hang               // Reserved
    .long Hang               // Reserved
    .long Hang               // Reserved
    .long Hang               // SVCall
    .long Hang               // Debug Monitor
    .long Hang               // Reserved
    .long Hang               // PendSV
    .long isr_systick	     // SysTick
    .long Hang               // IRQ000_Handler
    .long Hang               // IRQ001_Handler
    .long Hang               // IRQ002_Handler
    .long Hang               // IRQ003_Handler
    .long Hang               // IRQ004_Handler
    .long Hang               // IRQ005_Handler
    .long Hang               // IRQ006_Handler
    .long Hang               // IRQ007_Handler
    .long Hang               // IRQ008_Handler
    .long Hang               // IRQ009_Handler
    .long Hang               // IRQ010_Handler
    .long Hang               // IRQ011_Handler
    .long Hang               // IRQ012_Handler
    .long Hang               // IRQ013_Handler
    .long Hang               // IRQ014_Handler
    .long Hang               // IRQ015_Handler
    .long Hang               // IRQ016_Handler
    .long Hang               // IRQ017_Handler
    .long Hang               // IRQ018_Handler
    .long Hang               // IRQ019_Handler
    .long Hang               // IRQ020_Handler
    .long Hang               // IRQ021_Handler
    .long Hang               // IRQ022_Handler
    .long Hang               // IRQ023_Handler
    .long Hang               // IRQ024_Handler
    .long Hang               // IRQ025_Handler
    .long Hang               // IRQ026_Handler
    .long Hang               // IRQ027_Handler
    .long Hang               // IRQ028_Handler
    .long Hang               // IRQ029_Handler
    .long Hang               // IRQ030_Handler
    .long Hang               // IRQ031_Handler
    .long Hang               // IRQ032_Handler
    .long Hang               // IRQ033_Handler
    .long Hang               // IRQ034_Handler
    .long Hang               // IRQ035_Handler
    .long Hang               // IRQ036_Handler
    .long Hang               // IRQ037_Handler
    .long Hang               // IRQ038_Handler
    .long Hang               // IRQ039_Handler
    .long Hang               // IRQ040_Handler
    .long Hang               // IRQ041_Handler
    .long Hang               // IRQ042_Handler
    .long Hang               // IRQ043_Handler
    .long Hang               // IRQ044_Handler
    .long Hang               // IRQ045_Handler
    .long Hang               // IRQ046_Handler
    .long Hang               // IRQ047_Handler
    .long Hang               // IRQ048_Handler
    .long Hang               // IRQ049_Handler
    .long Hang               // IRQ050_Handler
    .long Hang               // IRQ051_Handler
    .long Hang               // IRQ052_Handler
    .long Hang               // IRQ053_Handler
    .long Hang               // IRQ054_Handler
    .long Hang               // IRQ055_Handler
    .long Hang               // IRQ056_Handler
    .long Hang               // IRQ057_Handler
    .long Hang               // IRQ058_Handler
    .long Hang               // IRQ059_Handler
    .long Hang               // IRQ060_Handler
    .long Hang               // IRQ061_Handler
    .long Hang               // IRQ062_Handler
    .long Hang               // IRQ063_Handler
    .long Hang               // IRQ064_Handler
    .long Hang               // IRQ065_Handler
    .long Hang               // IRQ066_Handler
    .long Hang               // IRQ067_Handler
    .long Hang               // IRQ068_Handler
    .long Hang               // IRQ069_Handler
    .long Hang               // IRQ070_Handler
    .long Hang               // IRQ071_Handler
    .long Hang               // IRQ072_Handler
    .long Hang               // IRQ073_Handler
    .long Hang               // IRQ074_Handler
    .long Hang               // IRQ075_Handler
    .long Hang               // IRQ076_Handler
    .long Hang               // IRQ077_Handler
    .long Hang               // IRQ078_Handler
    .long Hang               // IRQ079_Handler
    .long Hang               // IRQ080_Handler
    .long Hang               // IRQ081_Handler
    .long Hang               // IRQ082_Handler
    .long Hang               // IRQ083_Handler
    .long Hang               // IRQ084_Handler
    .long Hang               // IRQ085_Handler
    .long Hang               // IRQ086_Handler
    .long Hang               // IRQ087_Handler
    .long Hang               // IRQ088_Handler
    .long Hang               // IRQ089_Handler
    .long Hang               // IRQ090_Handler
    .long Hang               // IRQ091_Handler
    .long Hang               // IRQ092_Handler
    .long Hang               // IRQ093_Handler
    .long Hang               // IRQ094_Handler
    .long Hang               // IRQ095_Handler
    .long Hang               // IRQ096_Handler
    .long Hang               // IRQ097_Handler
    .long Hang               // IRQ098_Handler
    .long Hang               // IRQ099_Handler
    .long Hang               // IRQ100_Handler
    .long Hang               // IRQ101_Handler
    .long Hang               // IRQ102_Handler
    .long Hang               // IRQ103_Handler
    .long Hang               // IRQ104_Handler
    .long Hang               // IRQ105_Handler
    .long Hang               // IRQ106_Handler
    .long Hang               // IRQ107_Handler
    .long Hang               // IRQ108_Handler
    .long Hang               // IRQ109_Handler
    .long Hang               // IRQ110_Handler
    .long Hang               // IRQ111_Handler
    .long Hang               // IRQ112_Handler
    .long Hang               // IRQ113_Handler
    .long Hang               // IRQ114_Handler
    .long Hang               // IRQ115_Handler
    .long Hang               // IRQ116_Handler
    .long Hang               // IRQ117_Handler
    .long Hang               // IRQ118_Handler
    .long Hang               // IRQ119_Handler
    .long Hang               // IRQ120_Handler
    .long Hang               // IRQ121_Handler
    .long Hang               // IRQ122_Handler
    .long Hang               // IRQ123_Handler
    .long Hang               // IRQ124_Handler
    .long Hang               // IRQ125_Handler
    .long Hang               // IRQ126_Handler
    .long Hang               // IRQ127_Handler

.macro 	FUNCTION name                // this macro makes life less tedious. =)
       	.thumb_func					 // when a function is called by using 'bx' or 'blx' this is mandatory
       	.type \name, %function       // when a function is pointed to from a table, this is mandatory
       	.func \name,\name            // this tells a debugger that the function starts here
		.align						 // make sure the address is aligned for code output
       	\name:                       // this defines the label. the \() is necessary to separate the colon from the label
 		.endm

.macro	ENDFUNC name                 // FUNCTION and ENDFUNC must always be paired
		.size \name,.-\name 		 // tells the linker how big the code block for the function is
        .pool                        // let the assembler place constants here
		.endfunc					 // mark the end of the function, so a debugger can display it better
        .endm

// This function does intentionally hang. 
FUNCTION Hang
    B .
ENDFUNC Hang

// Trampoline for reset interrupt service routine
FUNCTION ResetTramp
	// Here the stack can be initialised. See above!
    B isr_reset				  // Call reset isr
ENDFUNC ResetTramp



      
