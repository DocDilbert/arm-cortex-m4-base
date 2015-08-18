#include <mcu.h>


/// End address of the text section.  
/// The text section is followed by the initial values of the data section.
/// This symbol is set by the linker. 
extern unsigned long _etext; 

/// Start address of the data section. This symbol is set by the linker.
extern unsigned long _data;  

/// End address of the data section. This symbol is set by the linker.
extern unsigned long _edata; 

/// Start address of the bss section. This symbol is set by the linker.
extern unsigned long _bss;   

/// End address of the bss section. This symbol is set by the linker.
extern unsigned long _ebss;  

/// \brief This function performs the basic system initialization.
///
/// When a reset is raised (e.g. at startup) this is the first function which gets called.
/// It performs the following tasks:
/// * Copy initial values to the data section in ram.
/// * Initialize the bss ram section with 0.
/// * PLL Configuration 
/// * SysTick Configuration
///
/// \ingroup StartSequence
void init()
{
    unsigned long *src, *dest;
    
    src = &_etext;
    for (dest = &_data; dest<&_edata;)
    {
        *dest++ = *src++;
    }
	
    for (src = &_bss; src<&_ebss;)
    {
        *src++ = 0;
    }
    
    SystemInit();
    SystemCoreClockUpdate();
    
	// Set the systick to 1 ms
    SysTick_Config(SystemCoreClock/1000);
}
