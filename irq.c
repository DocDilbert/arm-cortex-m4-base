#include "hw_gpio.h"

/// \brief System tick interrupt service handler
void systick_handler()
{
    HW_GPIO_TOGGLE(DEBUGPIN_1);
}