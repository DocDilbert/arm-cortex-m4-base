/// @file
///
/// This file contains the SysTickController class.
///
/// This class represent a software abstraction of the system tick interrupt.
///
/// @author Christian Groeling <ch.groeling@gmail.com>

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "utils.h"
#include "gpio.h"
#include "isr.h"

/// This class managed all systick related functionality.
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
    void isr();

private:
    IGpioPin* debugPin; ///< A pointer to the debug pin
    GpioDummyPin debugPinDummy; ///< A dummy gpio pin object  which is used when no debug pin was registered.
};



#endif
