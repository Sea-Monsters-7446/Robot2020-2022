#include <frc/Joystick.h>

#pragma once
/**
 * @brief A class used to keep track of the state of buttons for a joystick
 * 
 */
class buttonState {
  public:
  /**
   * @brief Construct a new buttonState object
   * 
   * @param joystick A joystick object created from frc/Joystick.h
   */
    buttonState(frc::Joystick& joystick);
    /**
     * @brief Updates the button states
     * 
     */
    void updateState();
    /**
     * @brief Checks if button 1 of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isButton1Pressed();
    /**
     * @brief Checks if button 2 of the joystic is pressed
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
     * @brief Checks if the trigger button of the joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isTriggerPressed();
    /**
     * @brief Checks to see if the top button of they joystick is pressed
     * 
     * @return true 
     * @return false 
     */
    bool isTopPressed();

  private:
    /**
     * @brief Struct that keeps track of the button state
     * 
     */
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
