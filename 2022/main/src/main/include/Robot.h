// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include "buttonState.h"

class Robot : public frc::TimedRobot {
 public:
  Robot();

  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  // Motors for the drive wheels
  frc::PWMVictorSPX m_leftMotor1;
  frc::PWMVictorSPX m_rightMotor1;
  frc::PWMVictorSPX m_leftMotor2;
  frc::PWMVictorSPX m_rightMotor2;
  // Motor for the launcher
  frc::PWMVictorSPX m_launcherMotor;
  // Motor for the conveyor belt
  frc::PWMVictorSPX m_conveyor;
  // Motors for the pickup mechanism
  frc::PWMVictorSPX m_pickupMech1;
  frc::PWMVictorSPX m_pickupMech2;

  frc::MotorControllerGroup m_leftMotor;
  frc::MotorControllerGroup m_rightMotor;
  // Motor group for the ball pickup mechanism
  frc::MotorControllerGroup m_pickupMech;
  
  frc::DifferentialDrive m_drive;
  frc::Joystick m_joystick;

  buttonState m_joystickButtons;
};