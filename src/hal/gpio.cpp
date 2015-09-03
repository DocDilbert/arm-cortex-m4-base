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




void GPIO_init()
{
    GPIO_INIT_OUT(DEBUGPIN_4, 0);

    // INITIALIZE LEDS
    GPIO_INIT_OUT(LED_RED, 1);
    GPIO_INIT_OUT(LED_GREEN, 1);
    GPIO_INIT_OUT(LED_BLUE, 1);
}
