
MEMORY {
    FLASH (rx): ORIGIN = 0x00000, LENGTH = 0x1000
    SRAM1 (rwx): ORIGIN = 0x1FFF0000, LENGTH = 0x1000
    SRAM2 (rwx): ORIGIN = 0x20000000, LENGTH = 0x1000
}
ENTRY(_Start)
SECTIONS
{
	.boot : {
		KEEP(*(.boot))
	} > FLASH
	
	.text : { 
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