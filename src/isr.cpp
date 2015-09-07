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

/// @brief This function is called when the systick irq is raised.
///
/// This function calls the registered interrupt service routine.
///
/// \attention C Linkage is required for all interrupt service routines.
extern "C" void ISR_Systick()
{
    // Call registered interrupt service routine
    pSysTickIsr->isr();
}

