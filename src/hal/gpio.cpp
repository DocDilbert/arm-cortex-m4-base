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

class GPIO_P1F : public GPIO
{
public:
    void setDDR()
    {
        printf("DebugPin1\n");
    }
};

class GPIODebugPin2 : public GPIO
{
public:
    void setDDR()
    {
        printf("DebugPin2\n");
    }
};

static GPIO_P1F gpio_P1F;

GPIO* gpios[PinsCount] = { &gpio_P1F };

GPIO* GPIOController::get(Pins pin)
{
    return gpios[pin];
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
