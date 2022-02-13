// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/time.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <units/time.h>
#include <frc2/command/button/JoystickButton.h>
#include "buttonState.h"

Robot::Robot() :
  m_leftMotor1(1),
  m_rightMotor1(2),
  m_leftMotor2(3),
  m_rightMotor2(4),
  m_yeeter(5),
  m_conveyor(6),
  m_pickupMech1(7),
  m_pickupMech2(8),
  m_leftMotor(m_leftMotor1, m_leftMotor2),
  m_rightMotor(m_rightMotor1, m_rightMotor2),
  m_pickupMech(m_pickupMech1, m_pickupMech2),
  m_drive(m_leftMotor, m_rightMotor),
  m_joystick(0),
  m_joystickButtons(m_joystick)
{
  
}

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
void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
  // For use with controller
  //m_drive.ArcadeDrive(m_controller.GetLeftY(), m_controller.GetRightX());
  // For use with joystick and simulation

  // Gets the X and Y of the joystick and controls the motor based on the values
  // The Y value of the joystick has to be reversed because the joystick is reversed
  // because of flight simulation and the way that is set up (up is down and down is up)
  m_joystickButtons.updateState();
  m_drive.ArcadeDrive((m_joystick.GetY() * -1), m_joystick.GetX());
  
  if (m_joystickButtons.isButton1Pressed()) {
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

  if (m_joystickButtons.isButton2Pressed()) {
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

  if (m_joystickButtons.isButton3Pressed()) {
    if (m_joystickButtons.isButton4Pressed()) {
      m_yeeter.Set(-1);
    }
    else {
      m_yeeter.Set(1);
    }
  }
  else {
    m_yeeter.Set(0);
  }
}
void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

void Robot::TestInit() {

}

void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
