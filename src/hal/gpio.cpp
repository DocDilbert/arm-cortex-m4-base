/// \file gpio.cpp
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

#include <stdio.h>
#include "gpio.h"

template<Pins pin>
    struct GpioRef : public GpioReference
    {
        virtual void set(bool state)
        {
            GPIOController::set<pin>(state);
        }
    };

GpioReference* GPIOController::getRef(Pins pin)
{
    switch (pin)
    {
        case DebugPin1:
            static GpioRef<DebugPin1> debugPin1;
            return &debugPin1;

        case DebugPin2:
            static GpioRef<DebugPin2> debugPin2;
            return &debugPin2;
    }
}

void GPIO_init()
{
    // INITIALIZE DEBUG PINS
    GPIO_INIT_OUT(DEBUGPIN_1, 0);

    GPIO_ADC_OFF(DEBUGPIN_2);
    GPIO_INIT_OUT(DEBUGPIN_2, 0);

    GPIO_ADC_OFF(DEBUGPIN_3);
    GPIO_INIT_OUT(DEBUGPIN_3, 0);

    GPIO_INIT_OUT(DEBUGPIN_4, 0);

    // INITIALIZE LEDS
    GPIO_INIT_OUT(LED_RED, 1);
    GPIO_INIT_OUT(LED_GREEN, 1);
    GPIO_INIT_OUT(LED_BLUE, 1);
}
