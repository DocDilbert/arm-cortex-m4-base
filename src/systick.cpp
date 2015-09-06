/// @file
///
/// This file contains the SysTickController class.
///
/// This class represent a software abstraction of the system tick interrupt.
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



