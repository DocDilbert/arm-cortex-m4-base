#ifndef __GPIO_DEF_H__
#define __GPIO_DEF_H__

#include "mcu.h"
#include "utils.h"

enum GpioLocation
{
    DebugPin1, DebugPin2, DebugPin3, DebugPin4
};
enum GpioFunction
{
    GPIO_OUTPUT
};
struct GPIOHardwareAccess
{
    template<GpioLocation pin>
        STATIC_INLINE void init(GpioFunction function);

    template<GpioLocation pin>
        STATIC_INLINE void set(const boolean_t state);

    template<GpioLocation pin>
        STATIC_INLINE boolean_t get();
};

// *********************************************************************
// DebugPin1 hardware access
// *********************************************************************
template<>
    INLINE void GPIOHardwareAccess::init<DebugPin1>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT:
                bFM4_GPIO_DDR1_PF = 1;
                bFM4_GPIO_PFR1_PF = 0;
                break;

            default:
                break;
        }
    }

template<>
    INLINE void GPIOHardwareAccess::set<DebugPin1>(const boolean_t state)
    {
        bFM4_GPIO_PDOR1_PF = state;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DebugPin1>()
    {
        // not implemented
        return false;
    }

// *********************************************************************
// DebugPin2 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::init<DebugPin2>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT:
                bFM4_GPIO_DDR1_PA = 1;
                bFM4_GPIO_PFR1_PA = 0;
                bFM4_GPIO_ADE_AN10 = 0; // disable adc
                break;

            default:
                break;
        }
    }

template<>
    INLINE void GPIOHardwareAccess::set<DebugPin2>(const boolean_t state)
    {
        bFM4_GPIO_PDOR1_PA = state;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DebugPin2>()
    {
        // not implemented
        return false;
    }

// *********************************************************************
// DebugPin3 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::init<DebugPin3>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT:
                bFM4_GPIO_DDR1_P9 = 1;
                bFM4_GPIO_PFR1_P9 = 0;
                bFM4_GPIO_ADE_AN09 = 0; // disable adc
                break;

            default:
                break;
        }
    }

template<>
    INLINE void GPIOHardwareAccess::set<DebugPin3>(const boolean_t state)
    {
        bFM4_GPIO_PDOR1_P9 = state;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DebugPin3>()
    {
        // not implemented
        return false;
    }

// *********************************************************************
// DebugPin4 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::init<DebugPin4>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT:
                bFM4_GPIO_DDR2_P5 = 1;
                bFM4_GPIO_PFR2_P5 = 0;
                break;

            default:
                break;
        }
    }

template<>
    INLINE void GPIOHardwareAccess::set<DebugPin4>(const boolean_t state)
    {
        bFM4_GPIO_PDOR2_P5 = state;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DebugPin4>()
    {
        // not implemented
        return false;
    }

#endif
