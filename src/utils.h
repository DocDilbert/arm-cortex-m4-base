/// \file utils.h
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __UTILS_H__
#define __UTILS_H__

/// Convenience macro. This macro sets the gcc attribute "alway_inline" and makes the function/method static inline.
#define STATIC_INLINE __attribute__( ( always_inline ) ) static inline

/// This function does burn cpu time.
/// TODO: input parameter
extern void UTILS_burnCpuTime();

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

#endif
