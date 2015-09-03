/// \file gpio.h
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

#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdio.h>
#include "mcu.h"
#include "base_types.h"
#include "gpioHardware.h"
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

// DEFINE GPIO MACROS

//@{
/// Aliases for bit banding registers
#define DEBUGPIN_1_DDR          bFM4_GPIO_DDR1_PF
#define DEBUGPIN_1_PDOR         bFM4_GPIO_PDOR1_PF
#define DEBUGPIN_1_PFR          bFM4_GPIO_PFR1_PF

#define DEBUGPIN_2_DDR          bFM4_GPIO_DDR1_PA
#define DEBUGPIN_2_PDOR         bFM4_GPIO_PDOR1_PA
#define DEBUGPIN_2_PFR          bFM4_GPIO_PFR1_PA
#define DEBUGPIN_2_ADE          bFM4_GPIO_ADE_AN10

#define DEBUGPIN_3_DDR          bFM4_GPIO_DDR1_P9
#define DEBUGPIN_3_PDOR         bFM4_GPIO_PDOR1_P9
#define DEBUGPIN_3_PFR          bFM4_GPIO_PFR1_P9
#define DEBUGPIN_3_ADE          bFM4_GPIO_ADE_AN09

#define DEBUGPIN_4_DDR          bFM4_GPIO_DDR2_P5
#define DEBUGPIN_4_PDOR         bFM4_GPIO_PDOR2_P5
#define DEBUGPIN_4_PFR          bFM4_GPIO_PFR2_P5

#define LED_RED_DDR             bFM4_GPIO_DDR2_P7
#define LED_RED_PDOR            bFM4_GPIO_PDOR2_P7
#define LED_RED_PFR             bFM4_GPIO_PFR2_P7

#define LED_GREEN_DDR           bFM4_GPIO_DDR3_P8
#define LED_GREEN_PDOR          bFM4_GPIO_PDOR3_P8
#define LED_GREEN_PFR           bFM4_GPIO_PFR3_P8

#define LED_BLUE_DDR            bFM4_GPIO_DDRE_P0
#define LED_BLUE_PDOR           bFM4_GPIO_PDORE_P0
#define LED_BLUE_PFR            bFM4_GPIO_PFRE_P0

//@}

/// A macro that toggles the logic-level of an output pin. The pin must be 
/// configured as gpio-output beforehand.
#define GPIO_TOGGLE(_PIN_) \
{\
    _PIN_##_PDOR ^= 0x1u; /* invert bit 1 */ \
}

/// A macro that sets the logic level of the given pin. The pin must be 
/// configured as gpio-output beforehand .
#define GPIO_PUT(_PIN_, _VALUE_) \
{\
    _PIN_##_PDOR= _VALUE_; /* Set the logic-level of the gpio */\
}

/// A macro that deactivates the usage of a pin as analog input.
#define GPIO_ADC_OFF(_PIN_) \
{\
    _PIN_##_ADE =0; /* deactivate usage of the pin as analog input*/ \
}

/// A macro that configures a pin as a gpio output.
///
/// Attention: adc functionality of a pin must be deactivated separately by using
/// the macro HW_GPIO_ADC_OFF .
#define GPIO_INIT_OUT(_PIN_, _INITIAL_VALUE_)\
{ \
    GPIO_PUT(_PIN_,_INITIAL_VALUE_); /* Set initial value of the output */ \
    _PIN_##_DDR=1u;  /* Set data direction to output*/ \
    _PIN_##_PFR=0u;  /* Set pin to gpio*/ \
}

/// This function initializes the gpio peripheral unit.
extern void GPIO_init();

struct GpioReference
{
    virtual void init(GpioFunction function) = 0;
    virtual void setLevel(const boolean_t state) const = 0;
    virtual void setHigh() const = 0;
    virtual void setLow() const = 0;
    virtual boolean_t get() const = 0;
};

template<GpioLocation pin>
    struct GpioReferenceHardware;

class GPIOController
{
public:
    template<GpioLocation pin>
        GpioReference* getRef()
        {
            static GpioReferenceHardware<pin> re;
            return &re;
        }
};

template<GpioLocation pin>
    struct GpioReferenceHardware : public GpioReference
    {
        INLINE void init(GpioFunction function)
        {
            GPIOHardwareAccess::init<pin>(function);
        }

        INLINE void setLevel(const boolean_t state) const
        {
            GPIOHardwareAccess::set<pin>(state);
        }

        INLINE void setHigh() const
        {
            GPIOHardwareAccess::set<pin>(true);
        }

        INLINE void setLow() const
        {
            GPIOHardwareAccess::set<pin>(false);
        }

        INLINE boolean_t get() const
        {
            return GPIOHardwareAccess::get<pin>();
        }
    };

#endif
