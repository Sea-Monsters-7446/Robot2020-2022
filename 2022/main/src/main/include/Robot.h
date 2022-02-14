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
/**
 * @brief Main robot class
 * @brief For more information on how to use WPILibC++ goto https://first.wpi.edu/wpilib/allwpilib/docs/release/cpp/index.html
 */
class Robot : public frc::TimedRobot {
 public:
/**
 * @brief Construct a new Robot object
 * 
 */
  Robot();
/**
 * @brief This function that gets called when the robot first turns on
 * 
 */
  void RobotInit() override;
/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
  void RobotPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Autonomous and it only gets called once per mode switch
 * 
 */
  void AutonomousInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Autonomous
 * 
 */
  void AutonomousPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Teleoperated and only gets called once per mode switch
 * 
 */
  void TeleopInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Teleoperated
 * 
 */
  void TeleopPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Disabled, or when you first start your robot and only gets called once per mode switch
 * 
 */
  void DisabledInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Disabled
 * 
 */
  void DisabledPeriodic() override;
/**
 * @brief This function gets called whenever the mode gets switched to Test and only gets called once per mode switch
 * 
 */
  void TestInit() override;
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Test
 * 
 */
  void TestPeriodic() override;

 private:
  // Motors for the drive wheels
  /**
   * @brief First left motor
   * 
   */
  frc::PWMVictorSPX m_leftMotor1;
  /**
   * @brief First right motot
   * 
   */
  frc::PWMVictorSPX m_rightMotor1;
  /**
   * @brief Second left motor
   * 
   */
  frc::PWMVictorSPX m_leftMotor2;
  /**
   * @brief Second right motot
   * 
   */
  frc::PWMVictorSPX m_rightMotor2;
  // Motor for the launcher
  /**
   * @brief Motor for the YEETER (launcher)
   * 
   */
  frc::PWMVictorSPX m_yeeter;
  // Motor for the conveyor belt
  /**
   * @brief Motor for the conveyor belt
   * 
   */
  frc::PWMVictorSPX m_conveyor;
  // Motors for the pickup mechanism
  /**
   * @brief Motor 1 for the pickup mechanism
   * 
   */
  frc::PWMVictorSPX m_pickupMech1;
  /**
   * @brief Motor 2 for the pickup mechanism
   * 
   */
  frc::PWMVictorSPX m_pickupMech2;
  /**
   * @brief Controller group for the two left motors
   * 
   */
  frc::MotorControllerGroup m_leftMotor;
  /**
   * @brief Controller group for the two left motors
   * 
   */
  frc::MotorControllerGroup m_rightMotor;
  // Motor group for the ball pickup mechanism
  /**
   * @brief Controller group for the pickup mechanism motors
   * 
   */
  frc::MotorControllerGroup m_pickupMech;
  /**
   * @brief The drive object
   * 
   */
  frc::DifferentialDrive m_drive;
  /**
   * @brief The joystick object
   * 
   */
  frc::Joystick m_joystick;
  /**
   * @brief The buttonState object
   * 
   */
  buttonState m_joystickButtons;
};