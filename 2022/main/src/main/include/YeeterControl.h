#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>

//typedef std::function<void(bool, bool)> YeeterControllerFunc; Use for later (Still learning)

/**
 * @brief A class for controlling our yeeter that yeets the balls for us
 * 
 * <p> Please note: `triggerButton` does not refer to the "trigger" button of the joystick. It
 * refers to the actual trigger that has to occur for this specified action to take place
 */
struct YeeterController {
public:
    /**
     * @brief Construct a new `YeeterController` object
     * 
     * @param yeeter THE YEETER object
     */
    YeeterController(frc::PWMVictorSPX& yeeter);
    /**
     * @brief Updates THE YEETER
     * 
     * @param triggerButton The trigger button of the joystick
     * @param shiftButton The shift button of the joystick
     */
    void operator()(bool triggerButton, bool shiftTriggerButton);

private:
    frc::PWMVictorSPX& m_yeeter;

    bool m_triggerSet;
    bool m_shiftSet;
};