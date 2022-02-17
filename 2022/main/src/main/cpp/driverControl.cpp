#include "Robot.h"
#include "ButtonState.h"
#include "DriverControl.h"

#include <frc/drive/DifferentialDrive.h>
/**
 * @brief Construct a new 'DriverController' object
 * 
 * 
 * @param drive The drive control object
 */
DriverController::DriverController(frc::DifferentialDrive& drive) :
    m_drive(drive)
{

}

/**
 * @brief Updates the position and movement of the wheels
 * 
 * @param x The x of the joystick
 * @param y The y of the joystick
 */
void DriverController::operator()(double x, double y) {
    m_drive.ArcadeDrive(y * -1, x);
}
