/// @file
///
/// File containing an abstract gpio access layer.
///
/// @author Christian Groeling <ch.groeling@gmail.com>
/// @ingroup Gpio

#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdio.h>
#include "base_types.h"
#include "gpioHal.h"
#include "utils.h"

/// @brief This module contains everything related to gpios.
///
/// The class GpioPin is the base class to all GpioHardwarePin classes. The GpioHardwarePin
/// classes do the actual hardware access to a pin. To do this, they use the template
/// methods defined in the GpioHal class.
///
/// @defgroup Gpio General Purpose Input Output

/// Base interface to all GpioHardwarePin and GpioDummyPin classes.
/// @ingroup Gpio
struct IGpioPin
{
    /// @brief This method initialize a gpio pin to be used for a given function.
    ///
    /// @param function The function for what the pin should be used.
    virtual void init(GpioFunction function) = 0;

    /// @brief This method sets the logic level of a gpio pin.
    /// @attention This method only works when the pin is configured as output.
    ///
    /// @param level The new logic level.
    virtual void setOut(const boolean_t level) const = 0;

    /// @brief This method sets the logic level of a gpio pin to high.
    /// @attention This method only works when the pin is configured as output.
    virtual void setOutHigh() const = 0;

    /// @brief This method sets the logic level of a gpio pin to low.
    /// @attention This method only works when the pin is configured as output.
    virtual void setOutLow() const = 0;

    /// @brief This method toggles the logic level of a gpio pin.
    /// @attention This method only works when the pin is configured as output.
    virtual void toggleOut() const = 0;

    /// @brief This method returns the actual logic level of a gpio pin.
    /// @attention This method only works when the pin is configured as input.
    ///
    /// @returns The measured logic level.
    virtual boolean_t getIn() const = 0;
};

/// This class defines a pin dummy object. This object does nothing. It can be used
/// to replace a hardware access to the gpios.
struct GpioDummyPin : public IGpioPin
{
    INLINE void init(GpioFunction function)
    {
    }

    INLINE void setOut(const boolean_t level) const
    {
    }

    INLINE void setOutHigh() const
    {
    }

    INLINE void setOutLow() const
    {
    }

    INLINE void toggleOut() const
    {
    }

    INLINE boolean_t getIn() const
    {
        return false;
    }
};

/// This template class is used to build access objects to the actual hardware. These access objects do all
/// share the same base class GpioPin.
///
/// @tparam pinId The pin identifier.
/// @ingroup Gpio
template<GpioPinId pinId>
    struct GpioHardwarePin : public IGpioPin
    {
        INLINE void init(GpioFunction function)
        {
            GpioHal::init<pinId>(function);
        }

        INLINE void setOut(const boolean_t level) const
        {
            GpioHal::setOut<pinId>(level);
        }

        INLINE void setOutHigh() const
        {
            GpioHal::setOut<pinId>(TRUE);
        }

        INLINE void setOutLow() const
        {
            GpioHal::setOut<pinId>(FALSE);
        }

        INLINE void toggleOut() const
        {
            GpioHal::toggleOut<pinId>();
        }

        INLINE boolean_t getIn() const
        {
            return GpioHal::getIn<pinId>();
        }
    };

/// This class administers all available GpioPin objects. The available
/// GpioPin objects are listed in the enum GpioPinId.
struct GpioController
{
    /// Get a pointer to the requested GpioPin object.
    ///
    /// @tparam pinId The pin identifier.
    template<GpioPinId pinId>
        IGpioPin* getPin()
        {
            static GpioHardwarePin<pinId> re;
            return &re;
        }
};

#endif
