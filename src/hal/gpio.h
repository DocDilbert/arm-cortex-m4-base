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

/// This class is the base object of all GpioHardwarePin objects.
struct GpioPin
{
    /// This methods initializes a gpio pin to be used for a given function.
    ///
    /// \param function The function for what the pin should be used.
    virtual void init(GpioFunction function) = 0;

    /// This method sets the logic level of a gpio pin. This only works when the pin is configured as output.
    ///
    /// \param level The logic level.
    virtual void setLevel(const boolean_t level) const = 0;

    /// This method sets the logic level of a gpio pin to high. This only works when the pin is configured as output.
    virtual void setHigh() const = 0;

    /// This method sets the logic level of a gpio pin to low. This only works when the pin is configured as output.
    virtual void setLow() const = 0;

    /// This method toggles the logic level of a gpio pin. This only works when the pin is configured as output.
    virtual void toggle() const = 0;

    /// This method gets the logic level of a gpio pin. This only works when the pin is configured as input.
    virtual boolean_t get() const = 0;
};

/// This class template is used to build access object to the actual hardware. These access objects do all
/// share the same base class GpioPin.
///
/// \tparam pinId The pin identifier.
template<GpioPinId pinId>
    struct GpioHardwarePin : public GpioPin
    {
        INLINE void init(GpioFunction function)
        {
            GPIOHardwareAccess::init<pinId>(function);
        }

        INLINE void setLevel(const boolean_t level) const
        {
            GPIOHardwareAccess::set<pinId>(level);
        }

        INLINE void setHigh() const
        {
            GPIOHardwareAccess::set<pinId>(true);
        }

        INLINE void setLow() const
        {
            GPIOHardwareAccess::set<pinId>(false);
        }

        INLINE void toggle() const
        {
            GPIOHardwareAccess::toggle<pinId>();
        }

        INLINE boolean_t get() const
        {
            return GPIOHardwareAccess::get<pinId>();
        }
    };

/// This class administers all GpioPin objects and their hardware parts.
struct GPIOController
{
    /// Get a pointer to the requested GpioPin object.
    ///
    /// \tparam pinId The pin identifier.
    template<GpioPinId pinId>
        GpioPin* getPin()
        {
            static GpioHardwarePin<pinId> re;
            return &re;
        }
};


#endif
