#pragma once

#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>

#include "ButtonState.h"
#include "Robot.h"


/**
 * @brief A class that is used to control and update the drive stuff you know (;
 * 
 */
struct DriverController {
public:
    /**
     * @brief Construct a new driverController object
     * 
     * @param drive The drive control object
     */
    DriverController(frc::DifferentialDrive& drive);
    /**
     * @brief Updates the position and movement of the wheels
     * 
     * @param x The x of the joystick
     * @param y The y of the joystick
     */
    void operator()(double x, double y);

private:
    frc::DifferentialDrive& m_drive;
};