/// \file gpio.h
///
/// File containing an abstract gpio access layer.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdio.h>
#include "base_types.h"
#include "gpioHardware.h"
#include "utils.h"

/// This abstract class is the base object of all GpioHardwarePin objects.
struct GpioPin
{
    /// This abstract methods initialize a gpio pin to be used for a given function.
    ///
    /// \param function The function for what the pin should be used.
    virtual void init(GpioFunction function) = 0;

    /// This abstract method sets the logic level of a gpio pin. It only works when the pin is configured as output.
    ///
    /// \param level The new logic level.
    virtual void setLevel(const boolean_t level) const = 0;

    /// This abstract method sets the logic level of a gpio pin to high. It only works when the pin is configured as output.
    virtual void setHigh() const = 0;

    /// This abstract method sets the logic level of a gpio pin to low. It only works when the pin is configured as output.
    virtual void setLow() const = 0;

    /// This abstract method toggles the logic level of a gpio pin. It only works when the pin is configured as output.
    virtual void toggle() const = 0;

    /// This abstract method gets the logic level of a gpio pin. It only works when the pin is configured as input.
    ///
    /// \return The measured logic level.
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
