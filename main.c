/// \file main.c
///
/// File containing the main() function. The main() function is the starting 
/// point of the program.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdio.h>
#include <stdint.h>
#include "hw_gpio.h"
#include "utils.h"



volatile uint32_t test = 0xDEADBEAF;
volatile uint32_t test2 = 0x2;

/// \brief This function is the starting point of the program. 
///
/// The function is called after the basic initialization of the system
/// has finished. It should not be leaved.
/// \ingroup StartSequence
void main()
{
    hw_gpio_init();
    test = 0;
    test = test + 1;

    test2 = test;
    while (1)
    {
        HW_GPIO_TOGGLE(DEBUGPIN_2);
        HW_GPIO_TOGGLE(DEBUGPIN_3);
        HW_GPIO_TOGGLE(DEBUGPIN_4);
        RED_LED_ON();
        burnCpuTime();
        RED_LED_OFF();
        burnCpuTime();
    }
    // do not leave this function
}
