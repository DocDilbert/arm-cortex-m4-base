/// \file main.cpp
///
/// File containing the main() function. The main() function is the starting 
/// point of the program.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include "base_types.h"
#include "gpio.h"
#include "utils.h"
#include "gpio.h"
/// \cond TEST
class A
{
public:
    A()
    {

    }
    A(int arg)
    {
        member = arg;
    }

    ~A()
    {
        member = -1;
    }
private:
    int member;
};

uint32_t data_test = 0xDEADBEAF;
uint8_t data_test2 = 0xDE;
uint16_t data_test3 = 0xDEAD;

uint32_t bss_test = 0;
uint8_t bss_test2;
uint16_t bss_test3;

const uint32_t read_only = 0x100;

uint16_t array_test[20];
uint16_t array_test2[10] = { 50, 60, 10 };
const uint16_t array_test3[10] = { 50, 60, 10 };

volatile A a_static(50);


RAMFUNC void ramTrampoline(GpioReference* debugPin)
{
    debugPin->setHigh();
    // This prevents that veneers are included to call UTILS_burn
    UTILS_simulateLoad(1000000);
    debugPin->setLow();
}

/// \endcond

GPIOController gpioCtrl;

GpioReference* debug1;
GpioReference* debug2;
GpioReference* debug3;
GpioReference* debug4;



/// \brief This function is the starting point of the program. 
///
/// The function is called after the reset irq was handled by isr_reset().
/// It should not be leaved.
///
/// \ingroup StartSequence
int main()
{
    static uint32_t cycles;
    volatile float32_t abs_in = -5.0;
    volatile float32_t abs_out = 0;
    A* a, *b;
    void* malloc_test[7];

    // Initialize gpios.
    debug1 = gpioCtrl.getRef<DebugPin1>();
    debug2 = gpioCtrl.getRef<DebugPin2>();
    debug3 = gpioCtrl.getRef<DebugPin3>();
    debug4 = gpioCtrl.getRef<DebugPin4>();

    GpioReference* led_red = gpioCtrl.getRef<LED_RED>();

    debug1->setLevel(FALSE);
    debug2->setLevel(FALSE);
    debug3->setLevel(FALSE);
    led_red->setLevel(FALSE);

    debug1->init(GPIO_OUTPUT);
    debug2->init(GPIO_OUTPUT);
    debug3->init(GPIO_OUTPUT);
    debug4->init(GPIO_OUTPUT);
    led_red->init(GPIO_OUTPUT);

    // turn off buffers, so IO occurs immediately
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    memset(array_test, 1, 5);

    abs_out = fabs(abs_in);

    a = new A(10);
    delete (a);

    b = new A[10];
    delete[] (b);

    malloc_test[0] = malloc(10);
    malloc_test[1] = malloc(13);
    malloc_test[2] = malloc(0x100);
    malloc_test[3] = malloc(0x500);
    malloc_test[4] = malloc(0x500);
    malloc_test[5] = malloc(0x500);
    malloc_test[6] = malloc(0x500);

    debug1->get();
    debug2->get();
    while (1)
    {
        printf("Hello World %i\n", cycles);
        cycles++;
        free(malloc_test[0]);
        malloc_test[0] = malloc(100);
        bss_test++;
        bss_test2++;
        bss_test3++;
        data_test++;
        data_test2++;
        data_test3++;

        led_red->setLow(); // red led on - inverse logic.

        ramTrampoline(debug2);

        led_red->setHigh(); // red led off - inverse logic.

        /*GPIO_PUT(DEBUGPIN_2, 1);
         UTILS_nopUnroll<500>();
         UTILS_nopUnroll<500>();
         GPIO_PUT(DEBUGPIN_2, 0);*/

        ramTrampoline(debug3);

        debug4->setHigh();

        debug4->setLow();
    }
    // never leave this function
    return -1;
}

