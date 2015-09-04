/// @file
///
/// File contains all code related to system reset.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __RESET_H__
#define __RESET_H__

/// @brief Short explanation of what happens when the system starts.
///
/// When the system starts a reset irq is raised. The reset irq jumps to the assembler function
/// reset_trampoline. This function calls:
///
/// * isr_reset() - This is the interrupt service routine for handling the reset irq.
/// * main() - After the reset isr finishes, the main routine is called. This should function should not be leaved.
///
/// @defgroup StartSequence System startup sequence


#endif
