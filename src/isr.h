#ifndef __ISR_H__
#define __ISR_H__

struct IInterruptServiceRoutine
{
    virtual void update() = 0;
};

/// This function registers an object which implements IInterrruptServiceRoutine interface.
/// The method update() of this objects is called each time a systick irq is raised.
void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController);

#endif
