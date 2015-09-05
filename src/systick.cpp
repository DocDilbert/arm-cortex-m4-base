/// @file
///
/// File contains systick related initialization and handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"
#include "gpio.h"

SysTickController *pSysTickController = NULL;

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

void registerSysTickControllerIsr(SysTickController *sysTickController)
{
    pSysTickController = sysTickController;
}

/// @brief System tick interrupt service routine.
///
/// This function is called when a systick irq is raised.
///
/// \attention C Linkage is required for interrupt service routines.
extern "C" void SYSTICK_trampoline()
{
    // Check if a valid object was registered
    if (pSysTickController != NULL)
        pSysTickController->isr();
}

