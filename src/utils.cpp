/// \file utils.cpp
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdio.h>
#include <stdint.h>
#include "utils.h"
#include "gpio.h"

void UTILS_simulateLoad(const unsigned cycles_10)
{
    __asm__(
            "CMP %0, #1      \n\t" // 1 cycle
            "BLS end_%=      \n\t"// 1 cycle / if %0 <= 1 then go to end_%
            "sub %0, #1      \n\t"// 1 cycle %0 = %0 - 1 :
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle
            "nop             \n\t"// 1 cycle                                       => 10 cycles
            "loop_%=:        \n\t"
            "   sub %0, #1   \n\t"// 1 cycle / %0 - 1
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   CMP %0, #0   \n\t"// 1 cycle / %0 = 0
            "   BNE loop_%=  \n\t"// 2 cycles when branch                          => 10 + cycles_10 * 10 - 1 cycles
            "nop             \n\t"// 1 cycle                                       => 10 + cycles_10 * 10  cycles
            "end_%=:         \n\t"

            : /* out */
            : "r"(cycles_10)/* in */
            : /* clobbers */);
}
