/// \file syscalls.c
///
/// File which contains all necessary stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>
#include <stdint.h>

/// \brief System call which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
void _exit (int32_t arg)
{
    while (1)
    {
    }
}
