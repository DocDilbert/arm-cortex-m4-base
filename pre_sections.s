// pre_sections.s
//
// This file is used to predefine sections which are later placed by the linker
//
// Author: Christian Groeling <ch.groeling@gmail.com>

.syntax unified
.thumb


// Define stack section
.equ StackSize, 0x00000400 // 1 KByte
.section ".stack", "wa" // create .stack section is writable(w) and allocatable(a)
.align 3	// stack must be 64 bit aligned
_stack_mem:
    .space StackSize


// Define heap section - used by malloc
.equ HeapSize,  0x00002000 // 8 kByte
.section ".heap", "wa" // create .heap section is writable(w) and allocatable(a)
.align 3 // heap must be 64 bit aligned
_heap_mem:
    .space HeapSize



