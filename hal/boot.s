.syntax unified
.thumb

// define section isr_vector. This section contains the isr_vectors and:
//
// hang - A function which intentionally hangs
// reset_trampoline - A function which calls isr_reset() and main()
//
.section .isr_vector,"xa"

.globl  _isr_vector_m
.type   _isr_vector_m, %object
_isr_vector_m:

	// The LSB of each exception vector indicates whether the exception is to be executed in the Thumb
	// state. Because the Cortex-M3/M4 can support only Thumb instructions, the LSB of all the exception vectors should be set to 1.
	//
	// This is done automatically by as. The jump itself ignores this bit, therefore all jumps are 32 Bit aligned.
	.align 2 // make sure the alignment is correct
	.long stack_top
	.long reset_trampoline   // Reset
	.long hang               // NMI
	.long hang               // Hard Fault
	.long hang               // MPU Fault
	.long hang               // Bus Fault
	.long hang               // Usage Fault
	.long hang               // Reserved
	.long hang               // Reserved
	.long hang               // Reserved
	.long hang               // Reserved
	.long hang               // SVCall
	.long hang               // Debug Monitor
	.long hang               // Reserved
	.long hang               // PendSV
	.long isr_systick	     // SysTick
	.long hang               // IRQ000_Handler
	.long hang               // IRQ001_Handler
	.long hang               // IRQ002_Handler
	.long hang               // IRQ003_Handler
	.long hang               // IRQ004_Handler
	.long hang               // IRQ005_Handler
	.long hang               // IRQ006_Handler
	.long hang               // IRQ007_Handler
	.long hang               // IRQ008_Handler
	.long hang               // IRQ009_Handler
	.long hang               // IRQ010_Handler
	.long hang               // IRQ011_Handler
	.long hang               // IRQ012_Handler
	.long hang               // IRQ013_Handler
	.long hang               // IRQ014_Handler
	.long hang               // IRQ015_Handler
	.long hang               // IRQ016_Handler
	.long hang               // IRQ017_Handler
	.long hang               // IRQ018_Handler
	.long hang               // IRQ019_Handler
	.long hang               // IRQ020_Handler
	.long hang               // IRQ021_Handler
	.long hang               // IRQ022_Handler
	.long hang               // IRQ023_Handler
	.long hang               // IRQ024_Handler
	.long hang               // IRQ025_Handler
	.long hang               // IRQ026_Handler
	.long hang               // IRQ027_Handler
	.long hang               // IRQ028_Handler
	.long hang               // IRQ029_Handler
	.long hang               // IRQ030_Handler
	.long hang               // IRQ031_Handler
	.long hang               // IRQ032_Handler
	.long hang               // IRQ033_Handler
	.long hang               // IRQ034_Handler
	.long hang               // IRQ035_Handler
	.long hang               // IRQ036_Handler
	.long hang               // IRQ037_Handler
	.long hang               // IRQ038_Handler
	.long hang               // IRQ039_Handler
	.long hang               // IRQ040_Handler
	.long hang               // IRQ041_Handler
	.long hang               // IRQ042_Handler
	.long hang               // IRQ043_Handler
	.long hang               // IRQ044_Handler
	.long hang               // IRQ045_Handler
	.long hang               // IRQ046_Handler
	.long hang               // IRQ047_Handler
	.long hang               // IRQ048_Handler
	.long hang               // IRQ049_Handler
	.long hang               // IRQ050_Handler
	.long hang               // IRQ051_Handler
	.long hang               // IRQ052_Handler
	.long hang               // IRQ053_Handler
	.long hang               // IRQ054_Handler
	.long hang               // IRQ055_Handler
	.long hang               // IRQ056_Handler
	.long hang               // IRQ057_Handler
	.long hang               // IRQ058_Handler
	.long hang               // IRQ059_Handler
	.long hang               // IRQ060_Handler
	.long hang               // IRQ061_Handler
	.long hang               // IRQ062_Handler
	.long hang               // IRQ063_Handler
	.long hang               // IRQ064_Handler
	.long hang               // IRQ065_Handler
	.long hang               // IRQ066_Handler
	.long hang               // IRQ067_Handler
	.long hang               // IRQ068_Handler
	.long hang               // IRQ069_Handler
	.long hang               // IRQ070_Handler
	.long hang               // IRQ071_Handler
	.long hang               // IRQ072_Handler
	.long hang               // IRQ073_Handler
	.long hang               // IRQ074_Handler
	.long hang               // IRQ075_Handler
	.long hang               // IRQ076_Handler
	.long hang               // IRQ077_Handler
	.long hang               // IRQ078_Handler
	.long hang               // IRQ079_Handler
	.long hang               // IRQ080_Handler
	.long hang               // IRQ081_Handler
	.long hang               // IRQ082_Handler
	.long hang               // IRQ083_Handler
	.long hang               // IRQ084_Handler
	.long hang               // IRQ085_Handler
	.long hang               // IRQ086_Handler
	.long hang               // IRQ087_Handler
	.long hang               // IRQ088_Handler
	.long hang               // IRQ089_Handler
	.long hang               // IRQ090_Handler
	.long hang               // IRQ091_Handler
	.long hang               // IRQ092_Handler
	.long hang               // IRQ093_Handler
	.long hang               // IRQ094_Handler
	.long hang               // IRQ095_Handler
	.long hang               // IRQ096_Handler
	.long hang               // IRQ097_Handler
	.long hang               // IRQ098_Handler
	.long hang               // IRQ099_Handler
	.long hang               // IRQ100_Handler
	.long hang               // IRQ101_Handler
	.long hang               // IRQ102_Handler
	.long hang               // IRQ103_Handler
	.long hang               // IRQ104_Handler
	.long hang               // IRQ105_Handler
	.long hang               // IRQ106_Handler
	.long hang               // IRQ107_Handler
	.long hang               // IRQ108_Handler
	.long hang               // IRQ109_Handler
	.long hang               // IRQ110_Handler
	.long hang               // IRQ111_Handler
	.long hang               // IRQ112_Handler
	.long hang               // IRQ113_Handler
	.long hang               // IRQ114_Handler
	.long hang               // IRQ115_Handler
	.long hang               // IRQ116_Handler
	.long hang               // IRQ117_Handler
	.long hang               // IRQ118_Handler
	.long hang               // IRQ119_Handler
	.long hang               // IRQ120_Handler
	.long hang               // IRQ121_Handler
	.long hang               // IRQ122_Handler
	.long hang               // IRQ123_Handler
	.long hang               // IRQ124_Handler
	.long hang               // IRQ125_Handler
	.long hang               // IRQ126_Handler
	.long hang               // IRQ127_Handler

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
FUNCTION hang
	B . // hang
ENDFUNC hang

// Trampoline for reset interrupt service routine
FUNCTION reset_trampoline
	// At this place some initialization can be done in assembler.
	// This is currently not necessary.
	B isr_reset	// Call reset isr
	B main		// Call main function
	B .			// This should not be reached
ENDFUNC reset_trampoline

