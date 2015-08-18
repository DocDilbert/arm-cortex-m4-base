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
/// * init() - Basic system initalization.
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
}

/// \brief System tick interrupt service handler
void systick_handler()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}

/// End address of the text section.  
/// The text section is followed by the initial values of the data section.
/// This symbol is set by the linker. 
extern unsigned long _etext; 

/// Start address of the data section. This symbol is set by the linker.
extern unsigned long _data;  

/// End address of the data section. This symbol is set by the linker.
extern unsigned long _edata; 

/// Start address of the bss section. This symbol is set by the linker.
extern unsigned long _bss;   

/// End address of the bss section. This symbol is set by the linker.
extern unsigned long _ebss;  

/// \brief This function performs the basic system initialization.
///
/// When a reset is raised (e.g. at startup) this is the first function which gets called.
/// It performs the following tasks:
/// * Copy initial values to the data section in ram.
/// * Initialize the bss ram section with 0.
/// * PLL Configuration 
/// * SysTick Configuration
///
/// \ingroup StartSequence
void init()
{
    unsigned long *src, *dest;
    
    src = &_etext;
    for (dest = &_data; dest<&_edata;)
    {
        *dest++ = *src++;
    }
	
    for (src = &_bss; src<&_ebss;)
    {
        *src++ = 0;
    }
    
    SystemInit();
    SystemCoreClockUpdate();
    
	// Set the systick to 1 ms
    SysTick_Config(SystemCoreClock/1000);
}

/// \}