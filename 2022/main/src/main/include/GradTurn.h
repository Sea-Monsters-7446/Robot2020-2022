#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>
/**
 * @brief A functor that turns the robot gradually
 * 
 */
struct GradualTurn {
    public:
    /**
     * @brief Construct a new GradualTurn object
     * 
     * @param leftMotor The left motor from a `frc::PWMVictorSPX` object
     * @param rightMotor The right motor from a `frc::PWMVictorSPX` object
     */
    GradualTurn(frc::PWMVictorSPX& leftMotor, frc::PWMVictorSPX& rightMotor);
    /**
     * @brief Turns thr robot
     * 
     * @param direction The direction you turn the robot
     * <p> positive will be left while negative will be right
     */
    void operator()(double direction);
    private:

    frc::PWMVictorSPX& m_leftMotor;
    frc::PWMVictorSPX& m_rightMotor;
};