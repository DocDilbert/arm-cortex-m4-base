#include "isr.h"

SysTickController *pSysTickController = NULL; ///< object which is used by the SYSTICK_trampoline.


void ISR_registerSysTick(SysTickController *sysTickController)
{
    pSysTickController = sysTickController;
}


/// @brief This function is called when the systick irq is raised.
///
/// This function calls the registered interrupt service routine.
///
/// \attention C Linkage is required for all interrupt service routine trampolines.
extern "C" void SYSTICK_trampoline()
{
    // Check if a valid object was registered
    if (pSysTickController != NULL)
        pSysTickController->isr();
}

