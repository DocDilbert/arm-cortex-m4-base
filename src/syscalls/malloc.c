/// \file malloc.c
///
/// This file contains all system calls which are needed by malloc to work properly.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <malloc.h>

/// Override of malloc lock function
void __malloc_lock(struct _reent *ptr)
{
    __asm__("nop");
}

/// Override of malloc unlock function
void __malloc_unlock(struct _reent *ptr)
{
    __asm__("nop");
}
