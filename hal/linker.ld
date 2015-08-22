
MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000
    SRAM2 (rwx): ORIGIN = 0x20000000, LENGTH = 0x1000
}
ENTRY(isr_reset)
SECTIONS
{
	. = ALIGN(4);

	.text : { 
		*(.isr_vector)
		*(.boot)	
		*(.text) 
        *(.rodata)
        _etext = .;
	} > FLASH
	
    .data : AT(_etext) {
        _data = .;
        *(.data)
        _edata = .;
	} > SRAM1
    
    .bss(NOLOAD) : {
		_bss = .;
		*(.bss)
		_ebss = .;
	} > SRAM1
    
    . = 0x20000000; /* Put stack SRAM2 */
	. = ALIGN(8);
	. = . + 0x1000; /* 4 kB stack */
    stack_top = .;
    
   
    
}