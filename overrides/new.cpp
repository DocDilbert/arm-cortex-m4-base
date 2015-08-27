/// \file new.cpp
///
/// This file contains implementations of the new operator which replace
/// the ones supplied by stdlibc++. This is done to save code and data memory
/// because the standard new operators use a lot of both.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdlib.h>
#include <stdio.h>

/// Simple new operator
/// \param size The size in bytes which should be allocated.
void *operator new(size_t size)
{
    void *p;
    // todo: Insert error checks here
    p = malloc(size);
    return p;
}

/// Array new operator
/// \param size The size in bytes which should be allocated.
void *operator new[](size_t size)
{
    void *p;
    // todo: Insert error checks here
    p = malloc(size);
    return p;
}
