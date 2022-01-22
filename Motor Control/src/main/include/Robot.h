// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>

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
  frc::PWMSparkMax m_leftMotor1{1};
  frc::PWMSparkMax m_rightMotor1{2};
  frc::DifferentialDrive m_drive{m_leftMotor1, m_rightMotor1};
  frc::Timer m_timer;
  frc::XboxController m_controller{0x01};
  frc::Joystick m_joystick{0};
};
