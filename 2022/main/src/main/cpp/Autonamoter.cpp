#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <tuple>

#include "Autonamoter.h"
#include "SafeData.hpp"
#include "PidIO.h"

AutonomousDrive::AutonomousDrive(frc::DifferentialDrive& drive, SafeData<std::tuple<double, double, double, double>>& safeData) :
    m_drive(drive),
    m_safeData(safeData),
    m_turnControl(0.0, 0.0, 0.0),
    m_speedControl(0.0, 0.0, 0.0),
    m_started(false)
{

}

int AutonomousDrive::pidInitialize(double proportional, double integral, double derivative, bool enableContinuousInput) {
    
    m_turnControl.SetPID(proportional, integral, derivative);
    m_speedControl.SetPID(proportional, integral, derivative);
    if (enableContinuousInput) {
        m_turnControl.EnableContinuousInput(-1, 1);
        m_speedControl.EnableContinuousInput(-1, 1);
    }
    return 1;
}

int AutonomousDrive::update() {
    if (!m_started) {
        return -1;
    }
    // Updates the PID values

    m_turnControl.Calculate(std::get<0>(m_safeData.get()));
    m_speedControl.Calculate(std::get<2>(m_safeData.get()));

    // Updates the motor values

    m_drive.ArcadeDrive(m_speedControl.GetSetpoint(), m_turnControl.GetSetpoint());
    return 1;
}