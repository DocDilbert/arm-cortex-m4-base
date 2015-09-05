/// @file
///
/// File containing the main() function. The main() function is the starting 
/// point of the program.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "base_types.h"
#include "systick.h"
#include "gpio.h"
#include "utils.h"

SysTickController sysTickCtrl; ///< The system tick controller object.
GpioController gpioCtrl; ///< The gpio controller object.

RAMFUNC void ramTrampoline(IGpioPin* debugPin)
{
    debugPin->setOutHigh();
    // This prevents that veneers are included to call UTILS_burn
    UTILS_simulateLoad(1000000);
    debugPin->setOutLow();
}

/// @brief This function is the starting point of the program. 
///
/// The function is called after the reset irq was handled by isr_reset().
/// It should not be leaved.
///
/// @ingroup StartSequence
int main()
{
    static uint32_t cycles;
    IGpioPin* debug1; ///< Global reference to debug pin 1 object
    IGpioPin* debug2; ///< Global reference to debug pin 2 object
    IGpioPin* debug3; ///< Global reference to debug pin 3 object
    IGpioPin* debug4; ///< Global reference to debug pin 4 object

    registerSysTickControllerIsr(&sysTickCtrl);

    // printf: turn off buffers, so IO occurs immediately.
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // Initialize gpios.
    debug1 = gpioCtrl.getPin<DEBUG_PIN1>();
    debug2 = gpioCtrl.getPin<DEBUG_PIN2>();
    debug3 = gpioCtrl.getPin<DEBUG_PIN3>();
    debug4 = gpioCtrl.getPin<DEBUG_PIN4>();

    IGpioPin* led_red = gpioCtrl.getPin<LED_RED>();

    debug1->init(GPIO_OUTPUT_LOW);
    debug2->init(GPIO_OUTPUT_LOW);
    debug3->init(GPIO_OUTPUT_LOW);
    debug4->init(GPIO_OUTPUT_LOW);

    // Register debug1 Pin to be used as systick isr debug pin.
    sysTickCtrl.registerDebugPin(debug1);

    led_red->init(GPIO_OUTPUT_LOW);

    while (1)
    {
        printf("Hello World %i\n", cycles);
        cycles++;

        led_red->setOutLow(); // red led on - inverse logic.
        ramTrampoline(debug2);
        led_red->setOutHigh(); // red led off - inverse logic.
        ramTrampoline(debug3);
    }
    // never leave this function
    return -1;
}

