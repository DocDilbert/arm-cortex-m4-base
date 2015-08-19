/// \file main.c
///
/// File containing the main() function which is the starting point of the program.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include "hw_gpio.h"

/// \brief Short explanation of what happens when the system starts.
///
/// When the system starts a reset irq is raised. The reset interrupt service
/// routine currently calls two functions.
/// * baseinit() - Basic system initalization.
/// * main() - Starting point.
///
/// \defgroup StartSequence System startup sequence

 
volatile int test = 0xDEADBEAF;
volatile test2 = 0x2;

void wait()
{
    unsigned i = 0;
    
    for (i=0;i<1000000;i++)
        asm("nop");
}

/// \brief This function is the starting point of the program. 
///
/// The function is called after the basic initialization of the system
/// has finished. It should not be leaved.
/// \ingroup StartSequence
void main()
{
    hw_gpio_init() ;
    test = 0;
    test = test +1;
    
    test2 = test;
    while(1)
    {
        HW_GPIO_TOGGLE(DEBUGPIN_2);
        HW_GPIO_TOGGLE(DEBUGPIN_3);
        HW_GPIO_TOGGLE(DEBUGPIN_4);
        RED_LED_ON();
        wait();
        RED_LED_OFF();
        wait();
    } 
	
	// do not leave this function
}