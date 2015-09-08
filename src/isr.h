/// @file
///
/// In this file an interface is defined which is used to register
/// abstract objects which do have an interrupt service routine.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __ISR_H__
#define __ISR_H__

/// @brief A simple class defining an interface for class which implements an interrupt service routine.
struct IInterruptServiceRoutine
{
    /// An interrupt service routine.
    virtual void isr() = 0;
};

/// @brief This function registers an object which implements IInterrruptServiceRoutine interface.
///
/// After successful registration the method isr() of this objects is called each time a
/// systick irq is raised.
void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController);

#endif
