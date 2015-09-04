/// @file
///
/// This file contains the _sbrk syscall. It is used to increase program data space.
///
/// @author Christian Groeling <ch.groeling@gmail.com>
/// @ingroup SystemCalls

#include <errno.h>

/// Libc error symbol. This is used to give more error details.
/// @ingroup SystemCalls
extern int errno;

/// Start address of the .heap section. This symbol is set by the linker.
extern int __heap_start;

/// Start address of the .heap section. This symbol is set by the linker.
extern int __heap_end;

/// @brief Increase program data space.
///
/// The _sbrk( ) function adds incr bytes to the break value and changes the allocated space
/// accordingly. If incr is negative, the amount of allocated space is decreased by incr bytes. The
/// current value of the program break is returned by sbrk(0).
///
/// @param incr Number of increments which should be added to the break value
///
/// @returns Upon successful completion, sbrk( ) returns the prior break value. Otherwise, it returns
///          (void *)−1 and sets errno to indicate the error.
///
/// @ingroup SystemCalls
void* _sbrk(int incr)
{
    static void *heap = NULL;
    void *prev_heap;
    void *new_heap;

    if (heap == NULL)
    {
        heap = (void *) &__heap_start;
    }

    prev_heap = heap;
    new_heap = heap + incr;

    if (new_heap < (void*) &__heap_end)
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
