/// @file
///
/// In this file all "C" interrupt service routines are implemented
///
/// Each interrupt service routine calls the isr() method of a registered
/// object which implements the IInterruptServiceRoutine interface.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include <stdint.h>
#include "mcu.h"
#include "base_types.h"
#include "isr.h"


/// Dummy class which implements an empty isr() method.
struct InterruptServiceRoutineDummy : public IInterruptServiceRoutine
{
    /// Implements IInterruptServiceRoutine::isr.
    ReturnCode isr()
    {
        // do nothing
        return RC_OK;
    }
};


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


InterruptServiceRoutineDummy isrDummy; ///< Dummy interrupt service routine object which is called when no valid object was registered.
IInterruptServiceRoutine *pSysTickIsr = &isrDummy; ///< object which is used by the SYSTICK_trampoline.

void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController)
{
    pSysTickIsr = sysTickController;
}

/// @brief Systick interrupt service routine
///
/// This function calls the registered systick interrupt service routine.
///
/// \attention C Linkage is required for all interrupt service routines.
extern "C" void ISR_Systick()
{
    // Call registered interrupt service routine
    pSysTickIsr->isr();
}

/// Hard fault interrupt service routine
///
/// A HardFault is an exception that occurs because of an error during exception processing, or because
/// an exception cannot be managed by any other exception mechanism. HardFaults have a fixed priority of -1,
/// meaning they have higher priority than any exception with configurable priority.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void ISR_HardFault()
{
    while (1)
    {
    }
}

/// Memory manage fault interrupt service routine
///
/// A MemManage fault is an exception that occurs because of a memory protection related fault. The the fixed memory
/// protection constraints determines this fault, for both instruction and data memory transactions. This fault is always
/// used to abort instruction accesses to Execute Never (XN) memory regions.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void ISR_MemManageFault()
{
    while (1)
    {
    }
}

/// Bus fault interrupt service routine
///
/// A BusFault is an exception that occurs because of a memory related fault for an instruction or data memory transaction.
/// This might be from an error detected on a bus in the memory system.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void ISR_BusFault()
{
    while (1)
    {
    }
}

/// Usage fault interrupt service routine
///
/// A UsageFault is an exception that occurs because of a fault related to instruction execution. This includes:
/// * an undefined instruction
/// * an illegal unaligned access
/// * invalid state on instruction execution
/// * an error on exception return.
///
/// The following can cause a UsageFault when the core is configured to report them:
/// * an unaligned address on word and halfword memory access
/// * division by zero.
///
/// \attention C Linkage is required for interrupt service routines.
///
extern "C" void ISR_UsageFault()
{
    while (1)
    {
    }
}



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
extern "C" void ISR_Reset()
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
