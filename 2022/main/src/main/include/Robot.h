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

class buttonState {
  public:
    buttonState(frc::Joystick& joystick);
    void updateState();
    bool isButton1Pressed();
    bool isButton2Pressed();
    bool isButton3Pressed();
    bool isButton4Pressed();
    bool isTriggerPressed();
    bool isTopPressed();

  private:
    struct m_buttonState {
      bool topPressed;
      bool triggerPressed;
      bool button1Pressed;
      bool button2Pressed;
      bool button3Pressed;
      bool button4Pressed;

    };
    m_buttonState joystickButtonState;
    frc::Joystick& m_joystick;

};

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