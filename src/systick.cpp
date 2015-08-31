/// \file systick.cpp
///
/// File contains systick related initialization and handling.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"

#include "gpio.h"

/// \brief System tick interrupt service routine.
///
/// This function is called when a systick irq is raised.
///
/// \attention C Linkage is required for interrupt service routines.
extern "C" void SYSTICK_isr()
{
    GPIO_TOGGLE(DEBUGPIN_1);
}

