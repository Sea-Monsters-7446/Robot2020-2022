#pragma once
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/time.h>
#include <frc/Timer.h>
#include <frc/Joystick.h>
#include <utility>
#include <thread>

#include "Robot.h"
#include "ButtonState.h"
#include "DriverControl.h"
#include "YeeterControl.h"
#include "PickupMechControl.h"
#include "ConveyorControl.h"
#include "SafeData.hpp"
#include "Vision.h"

/**
 * @brief Construct a new Robot object
 * 
 */
template<typename JoystickType>
Robot<JoystickType>::Robot() :
  m_leftMotor(1),
  m_rightMotor(2),
  m_yeeter(5),
  m_conveyor(6),
  m_pickupMech(7),
  m_drive(m_leftMotor, m_rightMotor),
  m_joystick(0),
  m_joystickButtons(m_joystick),
  m_driveControl(m_drive),
  m_yeeterControl(m_yeeter),
  m_pickupControl(m_pickupMech),
  m_conveyorControl(m_conveyor),
  m_visionSense(m_posibleBallPosition),
  m_visionThread()
{
  
}


/**
 * @brief This function that gets called when the robot first turns on
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::RobotInit() {
  m_visionThread = std::thread([this]() -> void {
    m_visionSense();
  });
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
template<typename JoystickType>
void Robot<JoystickType>::RobotPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Autonomous and it only gets called once per mode switch
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::AutonomousInit() {

}

/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Autonomous
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::AutonomousPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Teleoperated and only gets called once per mode switch
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::TeleopInit() {
}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Teleoperated
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::TeleopPeriodic() {

  m_driveControl(m_joystick.GetX(), m_joystick.GetY());

  m_yeeterControl(m_joystickButtons.isButton1Pressed(), m_joystickButtons.isButton4Pressed());

  m_pickupControl(m_joystickButtons.isButton2Pressed(), m_joystickButtons.isButton4Pressed());

  m_conveyorControl(m_joystickButtons.isButton3Pressed(), m_joystickButtons.isButton4Pressed());

}
/**
 * @brief This function gets called whenever the mode gets switched to Disabled, or when you first start your robot and only gets called once per mode switch
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::DisabledInit() {

}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Disabled
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::DisabledPeriodic() {

}
/**
 * @brief This function gets called whenever the mode gets switched to Test and only gets called once per mode switch
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::TestInit() {

}
/**
 * @brief This function is a loop that keeps getting called as long as the mode is set to Test
 * 
 */
template<typename JoystickType>
void Robot<JoystickType>::TestPeriodic() {
  
}


