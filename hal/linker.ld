SEARCH_DIR(.)

MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000     /* 4 KByte */
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000 /* 4 KByte */
}
ENTRY(reset_trampoline)
SECTIONS
{
	/* Place interrupt vector table */
	.isr_vector :  ALIGN(4) {
		/* KEEP - Do not delete .isr_vector sections even if they are not used */
		KEEP(*(.isr_vector)) 
	} > FLASH
	
	/* Place read only data */
	.rodata : ALIGN(4) {
		/* KEEP - Do not delete .rodata sections even if they are not used */
	   KEEP(*(.rodata)) 
	} > FLASH
	
	/* Place program code */
	.text : ALIGN(4) { 	
		*(.text) 
        _text_end = .;
	} > FLASH
	
	/* Place stack section. 64 Byte aligned. */
    .stack(NOLOAD) : ALIGN(8)
	{
    	*(.stack)
    	_stack_top = .;
  	} > SRAM1
	
	/* Place read-write initialized data */
    .data :  ALIGN(4) {
        _data_start = .;
        *(.data)
        _data_end = .;
	} > SRAM1 AT>FLASH
    
    /* Set start address of data load section which resides in flash */
    _data_lma_start = LOADADDR(.data);
    
    /* Place read-write zero initialized data. */
    .bss(NOLOAD) : ALIGN(4) {
		_bss_start = .;
    	*(.bss)
    	*(COMMON) /* Place common symbols into bss (e.g. unitialized globals). Attention they will be initialized with 0. */
		_bss_end = .;
	} > SRAM1
		

}