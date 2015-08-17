#include "hw_gpio.h"

void hw_gpio_init() 
{
  // INTIALIZE DEBUG PINS
  HW_GPIO_INIT_OUT(DEBUGPIN_1, 0);
  
  HW_GPIO_ADC_OFF(DEBUGPIN_2); 
  HW_GPIO_INIT_OUT(DEBUGPIN_2, 0);
  
  HW_GPIO_ADC_OFF(DEBUGPIN_3); 
  HW_GPIO_INIT_OUT(DEBUGPIN_3, 0);
  
  HW_GPIO_INIT_OUT(DEBUGPIN_4, 0);
  
  // INITIALIZE LEDS
  HW_GPIO_INIT_OUT(LED_RED, 1);
  HW_GPIO_INIT_OUT(LED_GREEN, 1);
  HW_GPIO_INIT_OUT(LED_BLUE, 1);
#ifdef _1_
  // Set PWM pins to output with level 0
  hw_gpio_disable_pwm_pins() ;
  
  /* Uses RTO0x_0 as the output pin of the waveform generator RTO0x.*/
  bFM4_GPIO_EPFR01_RTO00E0=1;
  bFM4_GPIO_EPFR01_RTO01E0=1;
  bFM4_GPIO_EPFR01_RTO02E0=1;
  bFM4_GPIO_EPFR01_RTO03E0=1;
  bFM4_GPIO_EPFR01_RTO04E0=1;
  bFM4_GPIO_EPFR01_RTO05E0=1;
#endif
}

#ifdef _1_

/* Sets the gpios RT00x to peripheral function, therefore enabling 
pwm output*/ 
void hw_gpio_enable_pwm_pins() 
{
  HW_GPIO_INIT_PERIPH_FUNC(RTO00_0);
  HW_GPIO_INIT_PERIPH_FUNC(RTO01_0);
  HW_GPIO_INIT_PERIPH_FUNC(RTO02_0);
  HW_GPIO_INIT_PERIPH_FUNC(RTO03_0);
}
#endif

/* Sets the gpios RT00x to gpios, therefore disabling pwm output*/
void hw_gpio_disable_pwm_pins() 
{
  HW_GPIO_INIT_OUT(RTO00_0, 0);
  HW_GPIO_INIT_OUT(RTO01_0, 0);
  HW_GPIO_INIT_OUT(RTO02_0, 0);
  HW_GPIO_INIT_OUT(RTO03_0, 0);
}