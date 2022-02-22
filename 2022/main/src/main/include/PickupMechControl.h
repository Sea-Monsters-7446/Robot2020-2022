#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>
/**
 * @brief A struct that is used to control the Pickup Mechanism
 * 
 * 
 * <p> Please note: `triggerButton` does not refer to the "trigger" button of the joystick. It
 * refers to the actual trigger that has to occur for this specified action to take place
 */
struct PickupController {
    /**
     * @brief Construct a new `PickupController` object
     * 
     * @param pickupMech The motor object for the Pickup Mechinism
     */
    PickupController(frc::PWMVictorSPX& pickupMech);
    /**
     * @brief Updates the PickupMech
     * 
     * @param triggerButton The trigger button of the joystick
     * @param shiftButton The shift button of the joystick
     */
    void operator()(bool triggerButton, bool shiftButton);

    private:
    
    frc::PWMVictorSPX& m_pickupMech;
};