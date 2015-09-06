#include "base_types.h"
#include "isr.h"

struct InterruptServiceRoutineDummy : public IInterruptServiceRoutine
{
    void update()
    {
        // do nothing
    }
};

InterruptServiceRoutineDummy isrDummy;
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
    pSysTickIsr->update();
}

