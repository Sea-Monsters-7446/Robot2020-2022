#include "buttonState.h"
#include <frc/Joystick.h>
/**
 * @brief Construct a new buttonState object
 * 
 * @param joystick A joystick object created from frc/Joystick.h
 */
buttonState::buttonState(frc::Joystick& joystick) :
  m_joystick(joystick)
{

}
/**
 * @brief Updates the button states
 * 
 */
void buttonState::updateState() {
  if (m_joystick.GetRawButtonPressed(1)) {
    joystickButtonState.button1Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(1)) {
    joystickButtonState.button1Pressed = false;
  }
  if (m_joystick.GetRawButtonPressed(2)) {
    joystickButtonState.button2Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(2)) {
    joystickButtonState.button2Pressed = false;
  }
  if (m_joystick.GetRawButtonPressed(3)) {
    joystickButtonState.button3Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(3)) {
    joystickButtonState.button3Pressed = false;
  }
  if (m_joystick.GetRawButtonPressed(4)) {
    joystickButtonState.button4Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(4)) {
    joystickButtonState.button4Pressed = false;
  }
  if (m_joystick.GetTopPressed()) {
    joystickButtonState.topPressed = true;
  }
  else if (m_joystick.GetTopReleased()) {
    joystickButtonState.topPressed = false;
  }
  if (m_joystick.GetTriggerPressed()) {
    joystickButtonState.triggerPressed = true;
  }
  else if (m_joystick.GetTriggerReleased()) {
    joystickButtonState.triggerPressed = false;
  }

}
/**
 * @brief Checks if button 1 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isButton1Pressed() {
  updateState();
  return joystickButtonState.button1Pressed;
}
/**
 * @brief Checks if button 2 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isButton2Pressed() {
  updateState();
  return joystickButtonState.button2Pressed;
}
/**
 * @brief Checks if button 3 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isButton3Pressed() {
  updateState();
  return joystickButtonState.button3Pressed;
}
/**
 * @brief Checks if button 4 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isButton4Pressed() {
  updateState();
  return joystickButtonState.button4Pressed;
}
/**
 * @brief Checks to see if the top button of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isTopPressed() {
  updateState();
  return joystickButtonState.topPressed;
}
/**
 * @brief Checks to see if the trigger of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool buttonState::isTriggerPressed() {
  updateState();
  return joystickButtonState.triggerPressed;
}
