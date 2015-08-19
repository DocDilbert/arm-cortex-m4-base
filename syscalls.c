/// \file syscalls.c
///
/// File which contains all necessary stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>


/// \brief System call which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
void _exit(int arg)
{
    while(1)
    {
    }
}
