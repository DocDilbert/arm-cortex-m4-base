/// \file syscalls.c
///
/// File containing stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>


/// \brief Hook which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
void _exit(int arg)
{
    while(1)
    {
    }
}
