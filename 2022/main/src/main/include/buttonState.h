#include <frc/Joystick.h>

#pragma once

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
