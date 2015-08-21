/// \file irq.c
///
/// File which contains all implemented interrupt service handlers.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "hw_gpio.h"

extern void main();
extern void baseinit();

/// \brief Reset interrupt service routine.
/// This function is called when a reset irq is raised. This usually happens
/// when the system is started.
void isr_reset()
{
	baseinit();
	main();
}

/// \brief System tick interrupt service routine.
/// This function is called when a systick irq is raised.
void isr_systick()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}