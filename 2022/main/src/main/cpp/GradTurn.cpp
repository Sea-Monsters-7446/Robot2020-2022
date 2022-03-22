#include "GradTurn.h"

/**
 * @brief Construct a new GradualTurn object
 * 
 */
GradualTurn::GradualTurn(frc::PWMVictorSPX& leftMotor, frc::PWMVictorSPX& rightMotor) :
    m_leftMotor(leftMotor),
    m_rightMotor(rightMotor)
{

}
/**
 * @brief Turns thr robot
 * 
 */
void GradualTurn::operator()(double direction) {
    if (direction > 0) {
        m_leftMotor.Set(direction);
    }
    if (direction < 0) {
        // Due to the configuration of our current prototype bot, this value has to be reversed from what it actually is.
        m_rightMotor.Set(abs(direction));
    }
}