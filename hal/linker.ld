SEARCH_DIR(.)

MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000
}
ENTRY(reset_trampoline)
SECTIONS
{
	/* Place interrupt vector table */
	.isr_vector : {
		. = ALIGN(4);
		*(.isr_vector) 
	} > FLASH
	
	/* Place read only data */
	.rodata : {
		. = ALIGN(4);
	   *(.rodata)
	} > FLASH
	
	/* Place program code */
	.text : { 	
		. = ALIGN(4);
		*(.text) 
        _text_end = .;
	} > FLASH
	
	/* Place stack section */
    .stack :
	{
    	*(.stack)
    	_stack_top = .;
  	} > SRAM1
	
	/* Place read-write initialized data */
    .data : AT(_text_end) {
    	. = ALIGN(4); 
        _data_start = .;
        *(.data)
        _data_end = .;
	} > SRAM1
    
    /* Place read-write zero initialized data. */
    .bss(NOLOAD) : {
    	. = ALIGN(4);
		_bss_start = .;
    	*(.bss)
    	*(COMMON) /* Place common symbols also into bss (e.g. unitialized globals) */
		_bss_end = .;
	} > SRAM1
		

}