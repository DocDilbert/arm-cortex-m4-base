/// @file
///
/// @brief This file contains the definition of the SysTickController class.
///
/// The SysTickController class represent a software interface to system tick peripheral
/// unit. This also includes an interrupt service routine which can be registered to be
/// called when a system tick interrupt is raised.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "utils.h"
#include "gpio.h"
#include "isr.h"
#include "return_code.h"

/// This class manages all systick related functionalities.
struct SysTickController : public IInterruptServiceRoutine
{
    SysTickController();

    /// @brief This method is  used to register a gpio pin for debugging purposes.
    ///
    /// The pin gets toggled each time the method isr is called.
    ///
    /// @param debugPin The debug pin which should be used.
    void registerDebugPin(IGpioPin *debugPin);

    /// Implements IInterruptServiceRoutine::isr()
    ReturnCode isr();

private:
    IGpioPin* debugPin; ///< A pointer to the debug pin
    GpioDummyPin debugPinDummy; ///< A dummy gpio pin object  which is used when no debug pin was registered.
};



#endif
