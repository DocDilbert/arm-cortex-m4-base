/// @file
///
/// In this file all "C" interrupt service routines are implemented
///
/// Each interrupt service routine calls the isr() method of a registered
/// object which implements the IInterruptServiceRoutine interface.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include "base_types.h"
#include "isr.h"

/// Dummy class which implements an empty isr() method.
struct InterruptServiceRoutineDummy : public IInterruptServiceRoutine
{
    /// Implements IInterruptServiceRoutine::isr.
    void isr()
    {
        // do nothing
    }
};

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

