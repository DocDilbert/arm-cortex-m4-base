#ifndef __ISR_H__
#define __ISR_H__

#include "systick.h"

/// This registers a given SysTickController isr() method to be called by the
/// systick trampoline function.
void ISR_registerSysTick(SysTickController *sysTickController);

#endif
