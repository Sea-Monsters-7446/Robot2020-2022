#include "YeeterControl.h"

#include <frc/motorcontrol/PWMVictorSPX.h>

/**
 * @brief Construct a new yeeterController object
 * 
 * @param yeeter THE yeeter object
 */
YeeterController::YeeterController(frc::PWMVictorSPX& yeeter) :
    m_yeeter(yeeter)
{

}

/**
 * @brief Updates the yeeter
 * 
 * @param triggerButton 
 * @param shiftTriggerButton 
 */
void YeeterController::operator()(bool triggerButton, bool shiftTriggerButton) {
    if (triggerButton) {
        m_yeeter.Set((shiftTriggerButton) ? -1 : 1);
    }
    else {
        m_yeeter.Set(0);
    }
}