/// \file delete.cpp
///
/// This file contains implementations of the delete operator which replace
/// the ones supplied by stdlibc++. This is done to save code and data memory
/// because the standard delete operators use a lot other methods.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdlib.h>
#include <stdio.h>

/// Simple delete operator
/// \param p Pointer of the, to be deleted, object
void operator delete(void *p)
{
    free(p);
}

/// Array delete operator
/// \param p Pointer of the, to be deleted, array of objects
void operator delete[](void *p)
{
    free(p);
}
