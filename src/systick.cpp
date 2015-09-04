/// \file
///
/// File contains systick related initialization and handling.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"

#include "gpio.h"
extern GpioPin* debug1;

/// \brief System tick interrupt service routine.
///
/// This function is called when a systick irq is raised.
///
/// \attention C Linkage is required for interrupt service routines.
extern "C" void SYSTICK_isr()
{
    debug1->toggle();
}

