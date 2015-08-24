/// \file systick.c
///
/// File contains systick related initialization and handling.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "systick.h"

#include "hal/gpio.h"

/// \brief System tick interrupt service routine.
/// This function is called when a systick irq is raised.
void isr_systick()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}

