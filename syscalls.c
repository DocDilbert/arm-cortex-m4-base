/// \file syscalls.c
///
/// File which contains all necessary stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

/// \brief System call which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#undef errno
extern int errno;

/// Start address of the .heap section. This symbol is set by the linker.
extern int _heap_start;

/// Start address of the .heap section. This symbol is set by the linker.
extern int _heap_end;

/// \brief Change space allocation
/// The _sbrk( ) function adds incr bytes to the break value and changes the allocated space
/// accordingly. If incr is negative, the amount of allocated space is decreased by incr bytes. The
/// current value of the program break is returned by sbrk(0).
///
/// \param incr Number of increments which should be added to the break value
void* _sbrk(int incr)
{
    static void *heap = NULL;
    void *prev_heap;
    void *new_heap;

    if (heap == NULL)
    {
        heap = (void *) &_heap_start;
    }

    prev_heap = heap;
    new_heap = heap + incr;

    if (new_heap < (void*)&_heap_end)
    {
        heap = new_heap;
        return (void*) prev_heap;
    }
    else
    {
        errno = ENOMEM;
        return ((void*) -1);
    }
}

