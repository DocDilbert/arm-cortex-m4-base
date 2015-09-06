/// @file
///
/// File contains systick related initialization and handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"
#include "gpio.h"


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



