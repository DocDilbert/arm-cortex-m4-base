MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000
    SRAM2 (rwx): ORIGIN = 0x20000000, LENGTH = 0x1000
}
ENTRY(reset_trampoline)
SECTIONS
{
	/* Place interrupt vector table */
	.isr_vector : {
		*(.isr_vector) 
	} > FLASH
	
	/* Place read only data */
	.rodata : {
	   *(.rodata)
	} > FLASH
	
	/* Place program code */
	.text : { 	
		*(.text) 
        text_end = .;
	} > FLASH
	
	/* Place read-write initialized data */ 
    .data : AT(text_end) {
        data_start = .;
        *(.data)
        data_end = .;
	} > SRAM1
    
    /* Place read-write zero initialized data. */
    .bss(NOLOAD) : {
		bss_start = .;
		*(.bss)
		bss_end = .;
	} > SRAM1
    
    . = 0x20000000; /* Put stack SRAM2 */
	. = ALIGN(8);
	. = . + 0x1000; /* 4 kB stack */
    stack_top = .;
    
   
    
}