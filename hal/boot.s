// boot.s
//
// File contains the interrupt vector table and a function which calls the boot code when a reset
// irq is raised.
//
// Author: Christian Groeling <ch.groeling@gmail.com>

.syntax unified
.thumb

// define  .isr_vector. This section contains the isr_vectors and:
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
	.long stack_top          // This entry is used at startup to initialize the top address of the stack
	.long reset_trampoline   // 000 - Reset
	.long hang               // 001 - NMI
	.long hang               // 002 - Hard Fault
	.long hang               // 003 - MPU Fault
	.long hang               // 004 - Bus Fault
	.long hang               // 005 - Usage Fault
	.long hang               // 006 - Reserved
	.long hang               // 007 - Reserved
	.long hang               // 008 - Reserved
	.long hang               // 009 - Reserved
	.long hang               // 010 - SVCall
	.long hang               // 011 - Debug Monitor
	.long hang               // 012 - Reserved
	.long hang               // 013 - PendSV
	.long isr_systick	     // 014 - SysTick

	// 015 - 143
	.rept 128                // Currently no fm4 irq is enabled. Fill the vector table with branches to hang
	.long hang               // xxx - IRQx_Handler
	.endr


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

	// The BL and BLX instructions write the address of the next instruction to LR (the link register, R14).
	BL isr_reset	// Branch with link to "isr_reset()", return address stored in LR (r14)
	BL main		// Branch with link to "main()", return address stored in LR (r14)
	B .			// This should not be reached
ENDFUNC reset_trampoline

