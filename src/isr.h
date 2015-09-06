/// @file
///
/// File contains interrupt service routine handling.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __ISR_H__
#define __ISR_H__

/// @brief Interface class implementing an interface service routine
struct IInterruptServiceRoutine
{
    /// An interrupt service routine.
    virtual void isr() = 0;
};

/// @brief This function registers an object which implements IInterrruptServiceRoutine interface.
///
/// After succesfull registration the method isr() of this objects is called each time a
/// systick irq is raised.
void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController);

#endif
