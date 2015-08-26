/// \file syscalls.c
///
/// File which contains all necessary stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

/// \brief System call which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
#include <sys/types.h>

void _exit(int arg)
{
    while (1)
    {
    }
}

extern int __HEAP_START;

caddr_t _sbrk(int incr)
{
    static unsigned char *heap = NULL;
    unsigned char *prev_heap;

    if (heap == NULL)
    {
        heap = (unsigned char *) &__HEAP_START;
    }
    prev_heap = heap;


    /* check removed to show basic approach */

    heap += incr;

    return (caddr_t) prev_heap;
}

