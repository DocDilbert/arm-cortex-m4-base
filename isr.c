/// \file isr.c
///
/// File which contains all implemented interrupt service handlers.
///
/// \author Christian Groeling <ch.groeling@gmail.com>


#include "baseinit.h"

extern void main();

/// \brief Reset interrupt service routine.
/// This function is called when a reset irq is raised. This usually happens
/// when the system is started.
void isr_reset()
{
    baseinit();
    main();
}

