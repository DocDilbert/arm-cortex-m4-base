SEARCH_DIR(.)

MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x2000    /* 8 KByte */
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x4000 /* 16 KByte */
}
ENTRY(reset_trampoline)
SECTIONS
{
	/* Place interrupt vector table */
	.isr_vectors :  ALIGN(4) {
		/* KEEP - Do not delete .isr_vector sections even if they are not used */
		KEEP(*(.isr_vectors)) 
	} > FLASH
	
	/* Place read only data */
	.rodata : ALIGN(4) {
		/* KEEP - Do not delete .rodata sections even if they are not used */
	   KEEP(*(.rodata .rodata.* )) 
	} > FLASH
	
	/* Place program code */
	.text : ALIGN(4) { 	
		 *(.text .text.*)
		 
	} > FLASH
	
	/* Place.init_array - function pointer to used for static initialization */
	.init_array : ALIGN(4) {
		__init_array_start = .;
		 KEEP (*(.init_array*))
		 __init_array_end = .;
	} > FLASH
	
	/* The following .ARM.extab section has something to do with stack frame unwinding */
	.ARM.extab   : 
	{ 
		*(.ARM.extab* .gnu.linkonce.armextab.*) 
	} >FLASH
	
	/* The following .ARM.extab section has something to do with stack frame unwinding */
    .ARM.exidx : {
   		__exidx_start = .;
     	*(.ARM.exidx*)
     	__exidx_end = .;
   	} >FLASH
   	
	/* Place stack section. 64 Byte aligned. */
    .stack(NOLOAD) : ALIGN(8)
	{
    	KEEP(*(.stack))
    	__stack_top = .;
  	} > SRAM1
	
	/* Place heap section. 64 Byte aligned. */
    .heap(NOLOAD) : ALIGN(8)
	{
		__heap_start = .;
    	KEEP(*(.heap))
    	__heap_end = .;
  	} > SRAM1
  	
	/* Place read-write initialized data */
    .data :  ALIGN(4) {
        __data_start = .;
       	*(.shdata)
    	*(.data .data.*)
        __data_end = .;
	} > SRAM1 AT>FLASH
    
    /* Set start address of data load section which resides in flash */
    __data_lma_start = LOADADDR(.data);
    
    /* Place read-write zero initialized data. */
    .bss(NOLOAD) : ALIGN(4) {
		__bss_start = .;
		
		 *(.shbss)
   		 *(.bss .bss.*)
    	*(COMMON) /* Place common symbols into bss (e.g. unitialized globals). Attention they will be initialized with 0. */
		__bss_end = .;
	} > SRAM1
	
	PROVIDE(__bss_start__ = __bss_start);
	PROVIDE(__bss_end__ = __bss_end);

}