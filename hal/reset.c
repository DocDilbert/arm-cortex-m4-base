/// \file reset.c
///
/// File contains all code related to system reset.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdint.h>
#include "mcu.h"

/// End address of the text section.  
/// The text section is followed by the initial values of the data section.
/// This symbol is set by the linker. 
extern uint32_t text_end;

/// Start address of the data section. This symbol is set by the linker.
extern uint32_t data_start;

/// End address of the data section. This symbol is set by the linker.
extern uint32_t data_end;

/// Start address of the bss section. This symbol is set by the linker.
extern uint32_t bss_start;

/// End address of the bss section. This symbol is set by the linker.
extern uint32_t bss_end;

/// \brief This function handles the reset irq
///
/// When a reset is raised (e.g. at startup) this is the first function which gets called.
/// It performs the following tasks:
/// * Copy initial values to the data section in ram.
/// * Initialize the bss ram section with 0.
/// * PLL Configuration
/// * SysTick Configuration
///
/// \ingroup StartSequence
void isr_reset()
{
    uint32_t *src, *dest;

    // Initialize the data section in ram with its initial values stored in flash.
    // The initial values a stored "after" the text section.
    src = &text_end;
    dest = &data_start;
    while (dest < &data_end)
    {
        *dest++ = *src++;
    }

    // Initialize the bss section with 0
    src = &bss_start;
    while (src < &bss_end)
    {
        *src++ = 0;
    }

    SystemInit();
    SystemCoreClockUpdate();

    // Set the systick to 1 ms
    SysTick_Config(SystemCoreClock / 1000);
}
