/// \file irq.c
///
/// File all interrupt serivce handlers.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "hw_gpio.h"

/// \brief System tick interrupt service handler
void systick_handler()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}