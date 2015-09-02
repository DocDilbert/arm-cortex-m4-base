/// \file utils.h
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __UTILS_H__
#define __UTILS_H__

/// Convenience macro. This macro sets the gcc attribute "alway_inline" and makes the function/method static inline.
#define STATIC_INLINE __attribute__( ( always_inline ) ) static inline

/// This macro moves a function into the .ramfuncs section
#define RAMFUNC __attribute__ ((section (".ramfuncs")))

/// This class injects a given number of nop's into the code.
///
/// \tparam count Number of nops which will be injected into the code.
template<unsigned count>
    struct NopUnroller
    {
        /// This method gets called when unrolling.
        STATIC_INLINE void nop()
        {
            __asm__("nop");
            NopUnroller<count - 1>::nop();
        }
    };
/// This class injects a given number of nop's into the code.
///
/// \attention This template finishes the template recursion.
template<>
    struct NopUnroller<0>
    {
        /// This method gets called when unrolling.
        STATIC_INLINE void nop()
        {
        }
    };

/// Convenience function which uses the NopUnroller class template to inject count
/// number of nops into the code.
///
/// \tparam count Number of nops which will be injected into the code.
template<unsigned count>
    STATIC_INLINE void UTILS_nopUnroll()
    {
        NopUnroller<count>::nop();
    }

/// This function waits "cycles_10" x 10 cpu cycles.
///
/// This function actively wait "cycles_10" x 10 instruction cycles. It is intentionally
/// placed in ram to prevent stall cycles which can occur executing it from flash.
///
/// \param cycles_10 Number of 10 times cycles to wait. All values equal or less than 4 are ignored.
///
 extern "C" RAMFUNC  __attribute__((optimize("O0"))) void UTILS_burn(const unsigned cycles_10);

#endif
