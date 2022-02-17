#include "ButtonState.h"
#include <frc/Joystick.h>
/**
 * @brief Construct a new `ButtonState` object
 * 
 * @param joystick A joystick object created from frc/Joystick.h
 * <p> This class is used to read the state of the joystick because we had trouble with reading the joysticks
 * state consistently
 */
ButtonState::ButtonState(frc::Joystick& joystick) :
  m_joystick(joystick)
{

}
/**
 * @brief Updates the button states
 * 
 */
void ButtonState::updateState() {
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

  if (m_joystick.GetRawButtonPressed(5)) {
    joystickButtonState.button5Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(5)) {
    joystickButtonState.button5Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(6)) {
    joystickButtonState.button6Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(6)) {
    joystickButtonState.button6Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(7)) {
    joystickButtonState.button7Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(7)) {
    joystickButtonState.button7Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(8)) {
    joystickButtonState.button8Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(8)) {
    joystickButtonState.button8Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(9)) {
    joystickButtonState.button9Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(9)) {
    joystickButtonState.button9Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(10)) {
    joystickButtonState.button10Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(10)) {
    joystickButtonState.button10Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(11)) {
    joystickButtonState.button11Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(11)) {
    joystickButtonState.button11Pressed = false;
  }

  if (m_joystick.GetRawButtonPressed(12)) {
    joystickButtonState.button12Pressed = true;
  }
  else if (m_joystick.GetRawButtonReleased(12)) {
    joystickButtonState.button12Pressed = false;
  }

}
/**
 * @brief Checks if button 1 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton1Pressed() {
  updateState();
  return joystickButtonState.button1Pressed;
}
/**
 * @brief Checks if button 2 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton2Pressed() {
  updateState();
  return joystickButtonState.button2Pressed;
}
/**
 * @brief Checks if button 3 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton3Pressed() {
  updateState();
  return joystickButtonState.button3Pressed;
}
/**
 * @brief Checks if button 4 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton4Pressed() {
  updateState();
  return joystickButtonState.button4Pressed;
}
/**
 * @brief Checks if button 5 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton5Pressed() {
  updateState();
  return joystickButtonState.button5Pressed;
}
/**
 * @brief Checks if button 6 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton6Pressed() {
  updateState();
  return joystickButtonState.button6Pressed;
}
/**
 * @brief Checks if button 7 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton7Pressed() {
  updateState();
  return joystickButtonState.button7Pressed;
}
/**
 * @brief Checks if button 8 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton8Pressed() {
  updateState();
  return joystickButtonState.button8Pressed;
}
/**
 * @brief Checks if button 9 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton9Pressed() {
  updateState();
  return joystickButtonState.button9Pressed;
}
/**
 * @brief Checks if button 10 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton10Pressed() {
  updateState();
  return joystickButtonState.button10Pressed;
}
/**
 * @brief Checks if button 11 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton11Pressed() {
  updateState();
  return joystickButtonState.button11Pressed;
}
/**
 * @brief Checks if button 12 of the joystick is pressed
 * 
 * @return true 
 * @return false 
 */
bool ButtonState::isButton12Pressed() {
  updateState();
  return joystickButtonState.button12Pressed;
}
