/// \file main.c
///
/// File containing the main() function. The main() function is the starting 
/// point of the program.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "base_types.h"
#include "hal/gpio.h"
#include "utils.h"

/// \cond TEST
volatile uint32_t test = 0xDEADBEAF;
volatile uint32_t test2 = 0x2;
/// \endcond

/// \brief This function is the starting point of the program. 
///
/// The function is called after the reset irq was handled by isr_reset().
/// It should not be leaved.
///
/// \ingroup StartSequence
void main()
{
    gpio_init();
    test = 0;
    test = test + 1;

    test2 = test;
    while (1)
    {
        GPIO_TOGGLE(DEBUGPIN_2);
        GPIO_TOGGLE(DEBUGPIN_3);
        GPIO_TOGGLE(DEBUGPIN_4);
        GPIO_RED_LED_ON();
        burnCpuTime();
        GPIO_RED_LED_OFF();
        burnCpuTime();
    }
    // do not leave this function
}
