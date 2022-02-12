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

class Robot : public frc::TimedRobot {
 public:
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
  frc::PWMVictorSPX m_leftMotor1{1};
  frc::PWMVictorSPX m_rightMotor1{2};
  frc::PWMVictorSPX m_leftMotor2{3};
  frc::PWMVictorSPX m_rightMotor2{4};
  frc::MotorControllerGroup m_leftMotor{m_leftMotor1, m_leftMotor2};
  frc::MotorControllerGroup m_rightMotor{m_rightMotor1, m_rightMotor2};

  frc::DifferentialDrive m_drive{m_leftMotor, m_rightMotor};
  frc::Timer m_timer;
  frc::XboxController m_controller{0x01};
  frc::Joystick m_joystick{0};
};
