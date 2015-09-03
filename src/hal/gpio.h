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

struct GpioReference
{
    virtual void init(GpioFunction function) = 0;
    virtual void setLevel(const boolean_t state) const = 0;
    virtual void setHigh() const = 0;
    virtual void setLow() const = 0;
    virtual void toggle() const = 0;
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

        INLINE void toggle() const
        {
            GPIOHardwareAccess::toggle<pin>();
        }

        INLINE boolean_t get() const
        {
            return GPIOHardwareAccess::get<pin>();
        }
    };

#endif
