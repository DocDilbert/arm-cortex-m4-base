/// @file
///
/// File contains systick related initialization and handling.
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

    /// Implements IInterruptServiceRoutine::update()
    void update();

private:
    IGpioPin* debugPin; ///< A pointer to the debug pin
    GpioDummyPin debugPinDummy; ///< A dummy gpio pin object  which is used when no debug pin was registered.
};



#endif
