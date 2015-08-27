// pre_sections.s
//
// This file is used to predefine sections which are later placed by the linker
//
// Author: Christian Groeling <ch.groeling@gmail.com>

.syntax unified
.thumb


// define stack section
.equ    Stack_Size, 0x00000400 // 1 KByte
.section ".stack", "wa" // create .stack section is writable(w) and allocatable(a)
.align  3	// stack must be 64 bit aligned
_stack_mem:
    .space  Stack_Size


// define heap section
// The malloc implementation of the newlibc uses 4 KByte pagesize.
// If the page size of malloc must be changed the newlibc must be recompiled.
// Another option is to provide an own implementation of malloc.
.equ    Heap_Size,  0x00002000 // 8 kByte
.section ".heap", "wa" // create .heap section is writable(w) and allocatable(a)
.align  3 // heap must be 64 bit aligned
_heap_mem:
    .space  Heap_Size



