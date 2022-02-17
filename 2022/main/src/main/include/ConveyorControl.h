#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>
/**
 * @brief Controls the conveyor
 * <p> Please note: `triggerButton` does not refer to the "trigger" button of the joystick. It
 * refers to the actual trigger that has to occur for this specified action to take place
 */
struct ConveyorController {
    /**
     * @brief Construct a new `ConveyorController` object
     * 
     * @param conveyor 
     */
    ConveyorController(frc::PWMVictorSPX& conveyor);
    /**
     * @brief Updates the conveyor
     * 
     * @param triggerButton The trigger button of the joystick
     * @param shiftButton The shift button of the joystick
     */
    void operator()(bool triggerButton, bool shiftButton);
private:
    frc::PWMVictorSPX& m_conveyor;
};