/// @file
///
/// File contains interrupt service routine handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __ISR_H__
#define __ISR_H__

/// Interface which an object implement to be called by the ISR module.
struct IInterruptServiceRoutine
{
    /// An interrupt service routine.
    virtual void isr() = 0;
};

/// This function registers an object which implements IInterrruptServiceRoutine interface.
/// The method update() of this objects is called each time a systick irq is raised.
void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController);

#endif
