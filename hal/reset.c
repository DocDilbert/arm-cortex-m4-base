/// \file reset.c
///
/// File contains all code related to system reset.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdint.h>
#include "mcu.h"

/// Start load address of the data section
extern uint32_t _data_lma_start;

/// Start address of the data section. This symbol is set by the linker.
extern uint32_t _data_start;

/// End address of the data section. This symbol is set by the linker.
extern uint32_t _data_end;

/// Start address of the bss section. This symbol is set by the linker.
extern uint32_t _bss_start;

/// End address of the bss section. This symbol is set by the linker.
extern uint32_t _bss_end;

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

    // Initialize the data section in ram with its initial values stored in flash
    src = &_data_lma_start;
    dest = &_data_start;

    while (dest < &_data_end)
    {
        *dest++ = *src++;
    }

    // Initialize the bss section with 0
    src = &_bss_start;
    while (src < &_bss_end)
    {
        *src++ = 0;
    }

    SystemInit();
    SystemCoreClockUpdate();

    // Set the systick to 1 ms
    SysTick_Config(SystemCoreClock / 1000);
}
