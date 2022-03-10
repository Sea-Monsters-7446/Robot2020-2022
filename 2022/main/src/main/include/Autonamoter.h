#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/controller/PIDController.h>
#include <tuple>

#include "SafeData.hpp"
#include "PidIO.h"

#pragma once
/**
 * @brief This is used to controll the wh
 * 
 */
class AutonomousDrive {
    public:
    /**
     * @brief Construct a new AutonomousMotor object
     * 
     * @param drive 
     * @param safeData 
     */
    AutonomousDrive(frc::DifferentialDrive& drive, SafeData<std::tuple<double, double, double, double>>& safeData);

    int pidInitialize(double proportional, double integral, double derivative, bool enableContinuousInput = false);

    int update();

    private:

    frc::DifferentialDrive& m_drive;
    SafeData<std::tuple<double, double, double, double>>& m_safeData;
    frc2::PIDController m_turnControl;
    frc2::PIDController m_speedControl;
    bool m_started;

};