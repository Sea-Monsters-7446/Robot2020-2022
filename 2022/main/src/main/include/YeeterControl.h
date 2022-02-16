#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>

//typedef std::function<void(bool, bool)> YeeterControllerFunc; Use for later (Still learning)

/**
 * @brief A class for controlling our yeeter that yeets the balls for us
 * 
 */
struct YeeterController {
public:
    /**
     * @brief Construct a new yeeterController object
     * 
     * @param yeeter THE yeeter object
     */
    YeeterController(frc::PWMVictorSPX& yeeter);

    void operator()(bool triggerButton, bool shiftTriggerButton);

private:
    /**
     * @brief Updates the yeeter
     * 
     */
    frc::PWMVictorSPX& m_yeeter;

    bool m_triggerSet;
    bool m_shiftSet;
};