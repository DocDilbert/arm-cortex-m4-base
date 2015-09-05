/// @file
///
/// File contains systick related initialization and handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"
#include "gpio.h"

SysTickController *pSysTickController = NULL; ///< object which is used by the SYSTICK_trampoline.

SysTickController::SysTickController()
{
    debugPin = &debugPinDummy;
}
void SysTickController::isr()
{
    debugPin->toggleOut();
}

void SysTickController::registerDebugPin(IGpioPin *debugPin)
{
    this->debugPin = debugPin;
}

void SYSTICK_registerIsr(SysTickController *sysTickController)
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

