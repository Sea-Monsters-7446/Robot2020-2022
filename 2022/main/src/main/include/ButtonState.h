#pragma once

#include <frc/Joystick.h>
#include <memory>

/**
 * @brief A class used to keep track of the state of buttons on a joystick
 * 
 */
class ButtonState {
  public:
    /**
     * @brief Construct a new `ButtonState` object
     * 
     */
    ButtonState(frc::GenericHID& joystick);
    /**
     * @brief Checks if button 1 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton1Pressed();
    /**
     * @brief Checks if button 2 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton2Pressed();
    /**
     * @brief Checks if button 3 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton3Pressed();
    /**
     * @brief Checks if button 4 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton4Pressed();
    /**
     * @brief Checks if button 5 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton5Pressed();
    /**
     * @brief Checks if button 6 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton6Pressed();
    /**
     * @brief Checks if button 7 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton7Pressed();
    /**
     * @brief Checks if button 8 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton8Pressed();
    /**
     * @brief Checks if button 9 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton9Pressed();
    /**
     * @brief Checks if button 10 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton10Pressed();
    /**
     * @brief Checks if button 11 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton11Pressed();
    /**
     * @brief Checks if button 12 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton12Pressed();
  private:
    /**
     * @brief Struct that keeps track of the button state
     * 
     */
    struct ButtonStateType {
      bool button1Pressed;
      bool button2Pressed;
      bool button3Pressed;
      bool button4Pressed;
      bool button5Pressed;
      bool button6Pressed;
      bool button7Pressed;
      bool button8Pressed;
      bool button9Pressed;
      bool button10Pressed;
      bool button11Pressed;
      bool button12Pressed;
    };
    /**
     * @brief Updates the button states
     * 
     */
    void updateState();
    
    ButtonStateType m_joystickButtonState;
    frc::GenericHID& m_joystick;

};
