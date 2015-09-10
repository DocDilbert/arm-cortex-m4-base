/// @file
///
/// @brief This file contains the implementation of the SysTickController class.
///
/// The SysTickController class represent a software interface to system tick peripheral
/// unit. This also includes an interrupt service routine which can be registered to be
/// called when a system tick interrupt is raised.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"
#include "gpio.h"

SysTickController::SysTickController()
{
    debugPin = &debugPinDummy;
}

ReturnCode SysTickController::isr()
{
    debugPin->toggleOut();
    return RC_OK;
}

void SysTickController::registerDebugPin(IGpioPin *debugPin)
{
    this->debugPin = debugPin;
}



