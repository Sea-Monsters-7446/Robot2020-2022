#include <frc/motorcontrol/PWMVictorSPX.h>

#include "ConveyorControl.h"

/**
 * @brief Construct a new `ConveyorController` object
 * 
 * @param conveyor 
 */
ConveyorController::ConveyorController(frc::PWMVictorSPX& conveyor) :
    m_conveyor(conveyor)
{

}
/**
 * @brief Updates the conveyor
 * 
 */
void ConveyorController::operator()(bool triggerButton, bool shiftButton) {
    if (triggerButton) {
        m_conveyor.Set((shiftButton) ? -0.5 : 0.5);
    }
    else {
        m_conveyor.Set(0);
    }
}