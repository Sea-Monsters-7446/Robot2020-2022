#include "Robot.h"
#include "buttonState.h"
#include "driverControl.h"

#include <frc/drive/DifferentialDrive.h>
/**
 * @brief Construct a new driverController object
 * 
 * 
 * @param drive The drive control object
 */
driverController::driverController(frc::DifferentialDrive& drive) :
    m_drive{drive}
{

}
/**
 * @brief Updates the position of the wheels
 * 
 * @param x X value of the joystick
 * @param y Y value of the joystick
 */
void driverController::update(double x, double y) {
    joystickAxis.x = x;
    joystickAxis.y = y * -1;
    updateWheels();
}
/**
 * @brief Update the position and movement of the wheels
 * 
 */
void driverController::updateWheels() {
    m_drive.ArcadeDrive(joystickAxis.y, joystickAxis.x);
}