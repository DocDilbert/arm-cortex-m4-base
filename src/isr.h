/// @file
///
/// In this file an interface is defined which is used to register
/// abstract objects which do have an interrupt service routine.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __ISR_H__
#define __ISR_H__

/// @brief Functions which get called when the system starts.
///
/// When the system starts a reset irq is raised. The reset irq jumps to the assembler function
/// reset_trampoline. This function calls:
///
/// * ISR_Reset() - This is the interrupt service routine for handling the reset irq.
/// * main() - After the reset isr finishes, the main routine is called. This should function should not be leaved.
///
/// @defgroup StartSequence System startup sequence



/// @brief A simple interface which has one abstract method which represent an interrupt service routine.
struct IInterruptServiceRoutine
{
    /// An interrupt service routine.
    virtual void isr() = 0;
};

/// @brief This function registers an object which implements IInterrruptServiceRoutine interface.
///
/// After successful registration the method isr() of the given objects is called each time a
/// systick irq is raised.
void ISR_registerSysTick(IInterruptServiceRoutine *sysTickController);

#endif
