/// @file
///
/// File contains systick related initialization and handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "utils.h"
#include "gpio.h"

struct SysTickController
{
    SysTickController();

    void registerDebugPin(IGpioPin *debugPin);

    /// Interrupt service routine with c++ linkage.
     void isr();

private:
    IGpioPin* debugPin;
    GpioDummyPin debugPinDummy;
};

/// This registers a given SysTickController isr method to be called by the
/// systick trampoline function.
void registerSysTickControllerIsr(SysTickController *sysTickController);



#endif
