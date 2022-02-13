#include "buttonState.h"
#include <frc/Joystick.h>

buttonState::buttonState(frc::Joystick& joystick) :
  m_joystick(joystick)
{

}

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
bool buttonState::isButton1Pressed() {

  return joystickButtonState.button1Pressed;
}

bool buttonState::isButton2Pressed() {
  return joystickButtonState.button2Pressed;
}

bool buttonState::isButton3Pressed() {
  return joystickButtonState.button3Pressed;
}

bool buttonState::isButton4Pressed() {
  return joystickButtonState.button4Pressed;
}

bool buttonState::isTopPressed() {
  return joystickButtonState.topPressed;
}

bool buttonState::isTriggerPressed() {
  return joystickButtonState.triggerPressed;
}
