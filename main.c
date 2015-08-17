#include "hw_gpio.h"

volatile int test = 0xDEADBEAF;
volatile test2 = 0x2;

void wait()
{
    unsigned i = 0;
    
    for (i=0;i<1000000;i++)
        asm("nop");
}

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

void _exit(int a)
{
    while(1)
    {
    }
}

void systick_handler()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}

extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss;
extern unsigned long _ebss;
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
    
    SysTick_Config(SystemCoreClock/1000);
}