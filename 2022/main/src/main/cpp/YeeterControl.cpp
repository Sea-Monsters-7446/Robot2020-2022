#include "YeeterControl.h"

#include <frc/motorcontrol/PWMVictorSPX.h>

/**
 * @brief Construct a new `YeeterController` object
 * 
 * @param yeeter THE YEETER object
 */
YeeterController::YeeterController(frc::PWMVictorSPX& yeeter) :
    m_yeeter(yeeter)
{

}

/**
 * @brief Updates THE YEETER
 * 
 */
void YeeterController::operator()(bool triggerButton, bool shiftButton) {
    if (triggerButton) {
        m_yeeter.Set((shiftButton) ? -1 : 1);
    }
    else {
        m_yeeter.Set(0);
    }
}