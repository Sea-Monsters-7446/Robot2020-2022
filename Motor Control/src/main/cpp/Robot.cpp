// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/time.h>
#include <frc/Timer.h>
#include <cstdint>
#include <frc/XboxController.h>
#include <frc/Joystick.h>

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
  // Resets the Timer
  m_timer.Reset();
}

void Robot::AutonomousPeriodic() {
  // Loops through and increases speed at an increment
  for (double times = 0x00; times < 0x01; times = times + 0.000001) {
  m_drive.ArcadeDrive(times, 0x00, true);
  }
  // Loops through and decreases speed at an increment
  for (double times = 0x00; times > -1; times = times - 0.000001) {
  m_drive.ArcadeDrive(times, 0x00, true);
  }
}

void Robot::TeleopInit() {
  // Resets the timer
  m_timer.Reset();
}

void Robot::TeleopPeriodic() {
  // For use with controller
  //m_drive.ArcadeDrive(m_controller.GetLeftY(), m_controller.GetRightX());
  // For use with joystick and simulation


  // Gets the X and Y data from the joystick and reports it back through
  // SmartDashboard
  m_drive.ArcadeDrive((m_joystick.GetY() * -1), m_joystick.GetX());
  if (m_joystick.GetX() > 0x00 && (m_joystick.GetY() * -1) > 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Right Forwards");
  }
  else if (m_joystick.GetX() > 0x00 &&(m_joystick.GetY() * -1) < 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Right Backwards");
  }
  else if (m_joystick.GetX() < 0x00 && (m_joystick.GetY() * -1) > 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Left Forwards");
  }
  else if (m_joystick.GetX() < 0x00 && (m_joystick.GetY() * -1) < 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Left Backwards");
  }
  else if (m_joystick.GetX() == 0x00 && (m_joystick.GetY() * -1) > 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Straight Forwards");
  }
  else if (m_joystick.GetX() == 0x00 && (m_joystick.GetY() * -1) < 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Straight Backwards");
  }
  else if (m_joystick.GetX() > 0x00 && (m_joystick.GetY() * -1) == 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Right");
  }
  else if (m_joystick.GetX() < 0x00 && (m_joystick.GetY() * -1) == 0x00) {
    frc::SmartDashboard::PutString("Direction:", "Left");
  }
  else {
    frc::SmartDashboard::PutString("Direction:", "Stationary");
  }

}

void Robot::DisabledInit() {
  // Starts a timer
  m_timer.Start();
}

void Robot::DisabledPeriodic() {
  // Prints back the number of seconds we have been in disabled mode to 
  // SmartDashboard
  frc::SmartDashboard::PutNumber("Time Disabled:", m_timer.Get().value());
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
