#ifndef __GPIO_DEF_H__
#define __GPIO_DEF_H__

#include "mcu.h"
#include "utils.h"

// IMPORTANT GPIO REGISTER DESCRIPTIONS
//
// ADE
// A register to set whether the I/O port will be used as a special pin (an analog input pin) or a digital input/output pin.
//
// PFR
// A register to set whether the I/O port will be used as an input/output pin of GPIO function or an input/output pin of
// peripheral functions.
//
// DDR
// A register to set whether the I/O port will be used as an input pin or an output pin if the I/O port is used as a GPIO
// function pin.
// Note: If a pin is selected as an I/O pin of peripheral functions, a setting value is invalid.
//
// PDOR
// A register to set output level if the I/O port is used as an output pin of GPIO function.
// -  When "0" is set, it outputs Low level.
// -  When "1" is set, it outputs High level.
// Note: If a pin is selected as GPIO input or input/output of peripheral functions, a setting value is invalid.

enum GpioPinId
{
    DEBUG_PIN1, DEBUG_PIN2, DEBUG_PIN3, DEBUG_PIN4, LED_RED, LED_GREEN, LED_BLUE
};
enum GpioFunction
{
    GPIO_OUTPUT_LOW ///<  Set the gpio function to output with initial low level
};

struct GPIOHardwareAccess
{
    template<GpioPinId pin>
        STATIC_INLINE void init(GpioFunction function);

    template<GpioPinId pin>
        STATIC_INLINE void set(const boolean_t level);

    template<GpioPinId pin>
        STATIC_INLINE void toggle();

    template<GpioPinId pin>
        STATIC_INLINE boolean_t get();
};

// *********************************************************************
// DebugPin1 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<DEBUG_PIN1>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_PF = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<DEBUG_PIN1>()
    {
        bFM4_GPIO_PDOR1_PF ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DEBUG_PIN1>()
    {
        // not implemented
        return false;
    }
template<>
    INLINE void GPIOHardwareAccess::init<DEBUG_PIN1>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<DEBUG_PIN1>(false);
                bFM4_GPIO_DDR1_PF = 1;
                bFM4_GPIO_PFR1_PF = 0;
                break;

            default:
                break;
        }
    }
// *********************************************************************
// DebugPin2 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<DEBUG_PIN2>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_PA = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<DEBUG_PIN2>()
    {
        bFM4_GPIO_PDOR1_PA ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DEBUG_PIN2>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<DEBUG_PIN2>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<DEBUG_PIN2>(false);
                bFM4_GPIO_DDR1_PA = 1;
                bFM4_GPIO_PFR1_PA = 0;
                bFM4_GPIO_ADE_AN10 = 0; // disable adc
                break;

            default:
                break;
        }
    }
// *********************************************************************
// DebugPin3 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<DEBUG_PIN3>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_P9 = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<DEBUG_PIN3>()
    {
        bFM4_GPIO_PDOR1_P9 ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DEBUG_PIN3>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<DEBUG_PIN3>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<DEBUG_PIN3>(false);
                bFM4_GPIO_DDR1_P9 = 1;
                bFM4_GPIO_PFR1_P9 = 0;
                bFM4_GPIO_ADE_AN09 = 0; // disable adc
                break;

            default:
                break;
        }
    }

// *********************************************************************
// DebugPin4 hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<DEBUG_PIN4>(const boolean_t level)
    {
        bFM4_GPIO_PDOR2_P5 = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<DEBUG_PIN4>()
    {
        bFM4_GPIO_PDOR2_P5 ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<DEBUG_PIN4>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<DEBUG_PIN4>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<DEBUG_PIN4>(false);
                bFM4_GPIO_DDR2_P5 = 1;
                bFM4_GPIO_PFR2_P5 = 0;
                break;

            default:
                break;
        }
    }

// *********************************************************************
// LED_RED hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<LED_RED>(const boolean_t level)
    {
        bFM4_GPIO_PDOR2_P7 = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<LED_RED>()
    {
        bFM4_GPIO_PDOR2_P7 ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<LED_RED>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<LED_RED>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<LED_RED>(false);
                bFM4_GPIO_DDR2_P7 = 1;
                bFM4_GPIO_PFR2_P7 = 0;
                break;

            default:
                break;
        }
    }

// *********************************************************************
// LED_GREEN hardware access
// *********************************************************************

template<>
    INLINE void GPIOHardwareAccess::set<LED_GREEN>(const boolean_t level)
    {
        bFM4_GPIO_PDOR3_P8 = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<LED_GREEN>()
    {
        bFM4_GPIO_PDOR3_P8 ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<LED_GREEN>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<LED_GREEN>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<LED_GREEN>(false);
                bFM4_GPIO_DDR3_P8 = 1;
                bFM4_GPIO_PFR3_P8 = 0;
                break;

            default:
                break;
        }
    }
// *********************************************************************
// LED_BLUE hardware access
// *********************************************************************


template<>
    INLINE void GPIOHardwareAccess::set<LED_BLUE>(const boolean_t level)
    {
        bFM4_GPIO_PDORE_P0 = level;
    }

template<>
    INLINE void GPIOHardwareAccess::toggle<LED_BLUE>()
    {
        bFM4_GPIO_PDORE_P0 ^= 0x1u;
    }

template<>
    INLINE boolean_t GPIOHardwareAccess::get<LED_BLUE>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GPIOHardwareAccess::init<LED_BLUE>(GpioFunction function)
    {
        switch (function)
        {
            case GPIO_OUTPUT_LOW:
                set<LED_BLUE>(false);
                bFM4_GPIO_DDRE_P0 = 1;
                bFM4_GPIO_PFRE_P0 = 0;
                break;

            default:
                break;
        }
    }

#endif
