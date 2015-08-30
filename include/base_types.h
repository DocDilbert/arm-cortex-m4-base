/// \file base_types.h
///
/// Additional base type definitions to stddef.h and stdint.h
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__

#include <stddef.h>
#include "stdint.h"

// **********************************************************************
// Global pre-processor symbols/macros ('#define')
// **********************************************************************
#ifndef TRUE
/// Value is true (boolean_t type)
#define TRUE        ((boolean_t) 1)
#endif

#ifndef FALSE
/// Value is false (boolean_t type)
#define FALSE       ((boolean_t) 0)
#endif  

/// Returns the minimum value out of two values
#define MIN( X, Y )  ((X) < (Y) ? (X) : (Y))

/// Returns the maximum value out of two values
#define MAX( X, Y )  ((X) > (Y) ? (X) : (Y))

/// Returns the dimension of an array
#define DIM( X )  (sizeof(X) / sizeof(X[0]))

// **********************************************************************
// Global type definitions
// **********************************************************************

/// logical datatype (only values are TRUE and FALSE)
typedef uint8_t boolean_t;

/// single precision floating point number (4 byte)
typedef float float32_t;

/// double precision floating point number (8 byte)
typedef double float64_t;

/// ASCCI character for string generation (8 bit)
typedef char char_t;

/// function pointer type to void/void function
typedef void (*func_ptr_t)(void);

/// function pointer type to void/uint8_t function
typedef void (*func_ptr_arg1_t)(uint8_t);

#endif

