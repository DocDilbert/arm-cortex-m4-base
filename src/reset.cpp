/// @file
///
/// File contains all code related to system reset.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include <stdint.h>
#include "base_types.h"
#include "mcu.h"

/// Start address of the data section. This symbol is set by the linker.
extern uint32_t __data_lma_start;

/// Start address of the .data initialization section. This symbol is set by the linker.
extern uint32_t __data_start;

/// End address of the .data section. This symbol is set by the linker.
extern uint32_t __data_end;

/// Start address of the .bss section. This symbol is set by the linker.
extern uint32_t __bss_start;

/// End address of the .bss section. This symbol is set by the linker.
extern uint32_t __bss_end;

/// Start address of the .init_array section. This symbol is set by the linker.
extern uint32_t __init_array_start;

/// End address of the .init_array section. This symbol is set by the linker.
extern uint32_t __init_array_end;

/// Start address of the .ramfuncs initialization section. This symbol is set by the linker.
extern uint32_t __ramfuncs_lma_start;

/// Start address of the .ramfuncs initialization section. This symbol is set by the linker.
extern uint32_t __ramfuncs_start;

/// End address of the .ramfuncs section. This symbol is set by the linker.
extern uint32_t __ramfuncs_end;



/// @brief This function handles the reset irq
///
/// When a reset is raised (e.g. at startup) this is the first function which gets called.
/// It performs the following tasks:
/// * Copy initial values to the data section in ram.
/// * Initialize the bss ram section with 0.
/// * PLL Configuration
/// * SysTick Configuration
///
/// \attention C Linkage is required for interrupt service routines.
///
/// @ingroup StartSequence
extern "C" void RESET_isr()
{
    uint32_t *src, *dest;
    // ------------------------------------------------------------------------------
    // Initialize the data section in ram with its initial values stored in flash
    // ------------------------------------------------------------------------------
    src = &__data_lma_start;
    dest = &__data_start;
    while (dest < &__data_end)
    {
        *dest++ = *src++;
    }

    // ------------------------------------------------------------------------------
    // Initialize the .ramfuncs section in ram with code stored in flash
    // ------------------------------------------------------------------------------
    src = &__ramfuncs_lma_start;
    dest = &__ramfuncs_start;
    while (dest < &__ramfuncs_end)
    {
        *dest++ = *src++;
    }
    // ------------------------------------------------------------------------------
    // Initialize the bss section with 0
    // ------------------------------------------------------------------------------
    src = &__bss_start;
    while (src < &__bss_end)
    {
        *src++ = 0;
    }

    // ------------------------------------------------------------------------------
    // Static initialization
    // ------------------------------------------------------------------------------
    src = &__init_array_start;
    while (src < &__init_array_end)
    {
        // Cast to function pointer
        func_ptr_t f = (func_ptr_t) (*(src++));
        (*f)();
    }

    // ------------------------------------------------------------------------------
    // System initialization - Usually provided by the chip vendor
    // ------------------------------------------------------------------------------
    SystemInit();
    SystemCoreClockUpdate();

    // Set the systick to 1 ms
    SysTick_Config(SystemCoreClock / 1000);
}
