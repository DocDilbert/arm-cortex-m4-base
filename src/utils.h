/// \file
///
/// File containing utility functions.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __UTILS_H__
#define __UTILS_H__

/// This macro sets the gcc attribute "alway_inline" and makes the function/method inline.
#define INLINE __attribute__( ( always_inline ) ) inline

/// This macro sets the gcc attribute "alway_inline" and makes the function/method static inline.
#define STATIC_INLINE __attribute__( ( always_inline ) ) static inline

/// This macro moves a function/method into the .ramfuncs section
#define RAMFUNC __attribute__ ((section (".ramfuncs")))

/// This macro sets the gcc attribute "optimize" to O0. It can be used to exclude functions/methods from compiler optimization.
#define DO_NOT_OPTIMIZE __attribute__((optimize("O0")))

/// This template class injects a given number of nops into the code.
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
/// \cond TEMPLATE_DOC

template<>
    struct NopUnroller<0>
    {
        /// This method gets called when unrolling.
        STATIC_INLINE void nop()
        {
        }
    };
/// \endcond

/// Convenience function which uses the NopUnroller class template to inject count
/// number of nops into the code.
///
/// \tparam count Number of nops which will be injected into the code.
template<unsigned count>
    STATIC_INLINE void UTILS_nopUnroll()
    {
        NopUnroller<count>::nop();
    }

/// This function simulates a cpu load. It will exit after approximately "cycles_10" x 10 cpu cycles.
///
/// This function actively wait "cycles_10" x 10 cpu cycles. It is intentionally
/// placed in ram to prevent stall cycles which can occur when executing it from flash.
/// Eventual overhead caused by the branch to this function and the return code which is
/// placed by gcc automatically is not considered. Therefore don't expect 100 % accurate results.
/// For big cycles_10 counts this can be neglected.
///
/// \param cycles_10 Number of 10 times cycles to wait. All values equal or less than 1 are ignored.
///
extern void UTILS_simulateLoad(const unsigned cycles_10);

#endif
