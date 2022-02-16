// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/time.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>

#include "Robot.h"
#include "ButtonState.h"
#include "DriverControl.h"
#include "YeeterControl.h"


/**
 * @brief Construct a new Robot object
 * 
 */
Robot::Robot() :
  m_leftMotor(1),
  m_rightMotor(2),
  m_yeeter(5),
  m_conveyor(6),
  m_pickupMech(7),
  m_drive(m_leftMotor, m_rightMotor),
  m_joystick(0),
  m_joystickButtons(m_joystick),
  m_driveControl(m_drive),
  m_yeeterControl(m_yeeter)
{
  
}

/**
 * @brief This function that gets called when the robot first turns on
 * 
 */
void Robot::RobotInit() {

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Autonomous and it only gets called once per mode switch
 * 
 */
void Robot::AutonomousInit() {
}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Autonomous
 * 
 */
void Robot::AutonomousPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Teleoperated and only gets called once per mode switch
 * 
 */
void Robot::TeleopInit() {
}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Teleoperated
 * 
 */
void Robot::TeleopPeriodic() {

  m_driveControl(m_joystick.GetX(), m_joystick.GetY());

  m_yeeterControl(m_joystickButtons.isButton1Pressed(), m_joystickButtons.isButton4Pressed());

  if (m_joystickButtons.isButton2Pressed()) {
    if (m_joystickButtons.isButton4Pressed()) {
      m_pickupMech.Set(-0.5);
    }
    else {
      m_pickupMech.Set(0.5);
    }
  }
  else {
    m_pickupMech.Set(0);
  }

  if (m_joystickButtons.isButton3Pressed()) {
    if (m_joystickButtons.isButton4Pressed()) {
      m_conveyor.Set(-0.5);
    }
    else {
      m_conveyor.Set(0.5);
    }
  }
  else {
    m_conveyor.Set(0);
  }
}
/**
 * @brief This function gets called whenever the mode gets switched to Disabled, or when you first start your robot and only gets called once per mode switch
 * 
 */
void Robot::DisabledInit() {

}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Disabled
 * 
 */
void Robot::DisabledPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Test and only gets called once per mode switch
 * 
 */
void Robot::TestInit() {

}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Test
 * 
 */
void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS
/**
 * @brief This only gets used for TESTS and was here by default. I don't know what it's meant for but keep it included.
 * 
 * @return int 
 */
int main() {
  return frc::StartRobot<Robot>();
}
#endif
