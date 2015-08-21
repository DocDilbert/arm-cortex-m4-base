/// \file baseinit.c
///
/// File which contains all code related to basic system initialization. The basic
/// system initialization "happens" before the main function is called.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdint.h>
#include "mcu.h"

/// End address of the text section.  
/// The text section is followed by the initial values of the data section.
/// This symbol is set by the linker. 
extern uint32_t _etext;

/// Start address of the data section. This symbol is set by the linker.
extern uint32_t _data;

/// End address of the data section. This symbol is set by the linker.
extern uint32_t _edata;

/// Start address of the bss section. This symbol is set by the linker.
extern uint32_t _bss;

/// End address of the bss section. This symbol is set by the linker.
extern uint32_t _ebss;

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
void baseinit()
{
    uint32_t *src, *dest;

    // Initialize the data section in ram with the default values stored in flash.
    // The default values a stored "after" the text section.
    src = &_etext;
    for (dest = &_data; dest < &_edata;)
    {
	*dest++ = *src++;
    }

    // Initialize the bss section with 0
    for (src = &_bss; src < &_ebss;)
    {
	*src++ = 0;
    }

    SystemInit();
    SystemCoreClockUpdate();

    // Set the systick to 1 ms
    SysTick_Config(SystemCoreClock / 1000);
}
