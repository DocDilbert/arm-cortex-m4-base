/// \file main.cpp
///
/// File containing the main() function. The main() function is the starting 
/// point of the program.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "base_types.h"
#include "hal/gpio.h"
#include "utils.h"


/// \cond TEST
uint32_t data_test = 0xDEADBEAF;
uint8_t data_test2 = 0xDE;
uint16_t data_test3 = 0xDEAD;

uint32_t bss_test = 0;
uint8_t bss_test2;
uint16_t bss_test3;

const uint32_t read_only = 0x100;

uint16_t array_test[20];
uint16_t array_test2[10] = {50,60,10};
const uint16_t array_test3[10] = {50,60,10};
/// \endcond

/// \brief This function is the starting point of the program. 
///
/// The function is called after the reset irq was handled by isr_reset().
/// It should not be leaved.
///
/// \ingroup StartSequence
int main()
{
    static uint32_t test;

    volatile float32_t abs_in = -5.0;
    volatile float32_t abs_out = 0;

    memset(array_test, 1, 5);

    abs_out = fabs(abs_in);
    // Initialize gpios.
    gpio_init();
    while (1)
    {
        bss_test++;
        bss_test2++;
        bss_test3++;
        data_test++;
        data_test2++;
        data_test3++;
        GPIO_TOGGLE(DEBUGPIN_2);
        GPIO_TOGGLE(DEBUGPIN_3);
        GPIO_TOGGLE(DEBUGPIN_4);
        GPIO_PUT(LED_RED, 0); // red led on - inverse logic.
        utils_burnCpuTime();
        GPIO_PUT(LED_RED, 1); // red led off - inverse logic.
        utils_burnCpuTime();
    }
    // never leave this function
    return -1;
}





