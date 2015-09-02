/// \file utils.cpp
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdio.h>
#include <stdint.h>
#include "utils.h"

void UTILS_burn(const unsigned cycles_10)
{
    __asm__("CMP %0, #2      \n\t"// 1 cycle
            "BLS end_%=      \n\t"// 1 cycle / if %0 <= 4 then go to end_%
            "sub %0, #4      \n\t"// 1 cycle %0 = %0 - 4 : -4 was measured.
            "nop             \n\t"// 1 cycle
            "loop_%=:        \n\t"
            "   sub %0, #1   \n\t"// 1 cycle / %0 - 1
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   nop          \n\t"// 1 cycle
            "   CMP %0, #0   \n\t"// 1 cycle / %0 = 0
            "   BNE loop_%=  \n\t"// 2 cycles when branch / 1 cycle when not
            "nop             \n\t"// 1 cycle
            "end_%=:             "
            : /* out */
            : "r"(cycles_10)/* in */
            :  /* clobbers */);
}
