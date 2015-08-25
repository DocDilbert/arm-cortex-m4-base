MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000
    SRAM2 (rwx): ORIGIN = 0x20000000, LENGTH = 0x1000
}
ENTRY(reset_trampoline)
SECTIONS
{
	/* Place interrupt vector table */
	. = ALIGN(4);
	.isr_vector : {
		*(.isr_vector) 
	} > FLASH
	
	/* Place read only data */
	. = ALIGN(4);
	.rodata : {
	   *(.rodata)
	} > FLASH
	
	/* Place program code */
	. = ALIGN(4);
	.text : { 	
		*(.text) 
        text_end = .;
	} > FLASH
	
	/* Place read-write initialized data */
	. = ALIGN(4); 
    .data : AT(text_end) {
        data_start = .;
        *(.data)
        data_end = .;
	} > SRAM1
    
    /* Place read-write zero initialized data. */
    . = ALIGN(4);
    .bss(NOLOAD) : {
		bss_start = .;
		*(.bss)
		bss_end = .;
	} > SRAM1
	
	/* Place stack section */
    .stack :
	{
    	*(.stack)
    	stack_top = .;
  	} > SRAM2

}