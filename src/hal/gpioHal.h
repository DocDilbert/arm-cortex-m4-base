/// \file
///
/// File containing the gpio hardware abstraction.
///
/// Each cortex-m4 based microcontroller has its own way dealing with gpios. The functions
/// in this file should deliver an hardware independent interface to access these.
///
/// This file is written for the spansion/cypress MB9BF568R. But is should be easily
/// adaptable to other microcontrollers.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __GPIO_DEF_H__
#define __GPIO_DEF_H__

#include "mcu.h"
#include "base_types.h"
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

/// This enum lists all currently supported Pins.
enum GpioPinId
{
    DEBUG_PIN1, DEBUG_PIN2, DEBUG_PIN3, DEBUG_PIN4, LED_RED, LED_GREEN, LED_BLUE
};

/// This enum lists all possible gpio functions.
enum GpioFunction
{
    GPIO_OUTPUT_LOW ///<  Set the gpio function to output with initial low level
};

/// This class contains static template methods which perform the actual hardware accesses. For each pin identifier
/// all methods contained in this class must be specialized.
struct GpioHal
{
    /// This template method initializes a gpio pin to be used for a given function.
    ///
    /// \tparam pinId The pin identifier.
    /// \param function The function for what the pin should be used.
    template<GpioPinId pinId>
        STATIC_INLINE void init(GpioFunction function);

    /// This template method sets the logic level of a gpio pin. It only works when the pin is configured as output.
    ///
    /// \tparam pinId The pin identifier.
    /// \param level The new logic level.
    template<GpioPinId pinId>
        STATIC_INLINE void set(const boolean_t level);

    /// This template method toggles the logic level of a gpio pin. It only works when the pin is configured as output.
    ///
    /// \tparam pinId The pin identifier.
    template<GpioPinId pinId>
        STATIC_INLINE void toggle();

    /// This template method gets the logic level of a gpio pin. It only works when the pin is configured as input.
    ///
    /// \tparam pinId The pin identifier.
    /// \returns The measured logic level.
    template<GpioPinId pinId>
        STATIC_INLINE boolean_t get();
};

/// \cond TEMPLATE_DOC

// *********************************************************************
// DebugPin1 hardware access
// *********************************************************************

template<>
    INLINE void GpioHal::set<DEBUG_PIN1>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_PF = level;
    }

template<>
    INLINE void GpioHal::toggle<DEBUG_PIN1>()
    {
        bFM4_GPIO_PDOR1_PF ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<DEBUG_PIN1>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<DEBUG_PIN1>(GpioFunction function)
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
    INLINE void GpioHal::set<DEBUG_PIN2>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_PA = level;
    }

template<>
    INLINE void GpioHal::toggle<DEBUG_PIN2>()
    {
        bFM4_GPIO_PDOR1_PA ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<DEBUG_PIN2>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<DEBUG_PIN2>(GpioFunction function)
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
    INLINE void GpioHal::set<DEBUG_PIN3>(const boolean_t level)
    {
        bFM4_GPIO_PDOR1_P9 = level;
    }

template<>
    INLINE void GpioHal::toggle<DEBUG_PIN3>()
    {
        bFM4_GPIO_PDOR1_P9 ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<DEBUG_PIN3>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<DEBUG_PIN3>(GpioFunction function)
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
    INLINE void GpioHal::set<DEBUG_PIN4>(const boolean_t level)
    {
        bFM4_GPIO_PDOR2_P5 = level;
    }

template<>
    INLINE void GpioHal::toggle<DEBUG_PIN4>()
    {
        bFM4_GPIO_PDOR2_P5 ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<DEBUG_PIN4>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<DEBUG_PIN4>(GpioFunction function)
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
    INLINE void GpioHal::set<LED_RED>(const boolean_t level)
    {
        bFM4_GPIO_PDOR2_P7 = level;
    }

template<>
    INLINE void GpioHal::toggle<LED_RED>()
    {
        bFM4_GPIO_PDOR2_P7 ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<LED_RED>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<LED_RED>(GpioFunction function)
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
    INLINE void GpioHal::set<LED_GREEN>(const boolean_t level)
    {
        bFM4_GPIO_PDOR3_P8 = level;
    }

template<>
    INLINE void GpioHal::toggle<LED_GREEN>()
    {
        bFM4_GPIO_PDOR3_P8 ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<LED_GREEN>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<LED_GREEN>(GpioFunction function)
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
    INLINE void GpioHal::set<LED_BLUE>(const boolean_t level)
    {
        bFM4_GPIO_PDORE_P0 = level;
    }

template<>
    INLINE void GpioHal::toggle<LED_BLUE>()
    {
        bFM4_GPIO_PDORE_P0 ^= 0x1u;
    }

template<>
    INLINE boolean_t GpioHal::get<LED_BLUE>()
    {
        // not implemented
        return false;
    }

template<>
    INLINE void GpioHal::init<LED_BLUE>(GpioFunction function)
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
/// \endcond
#endif
