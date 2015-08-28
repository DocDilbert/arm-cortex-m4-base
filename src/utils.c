/// \file utils.h
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdio.h>
#include <stdint.h>
#include "utils.h"

void utils_burnCpuTime()
{
    uint32_t i = 0;

    for (i = 0; i < 1000000; i++)
        __asm__("nop");
}
