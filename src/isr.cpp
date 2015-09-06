#include "base_types.h"
#include "isr.h"

IInterruptServiceRoutine *pSysTickController = NULL; ///< object which is used by the SYSTICK_trampoline.


void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController)
{
    pSysTickController = sysTickController;
}


/// @brief This function is called when the systick irq is raised.
///
/// This function calls the registered interrupt service routine.
///
/// \attention C Linkage is required for all interrupt service routine trampolines.
extern "C" void ISR_Systick()
{
    // Check if a valid object was registered
    if (pSysTickController != NULL)
        pSysTickController->update();
}

