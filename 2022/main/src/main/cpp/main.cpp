#include "Robot.hpp"

#ifndef RUNNING_FRC_TESTS
/**
 * @brief This only gets used by non tests
 * 
 * @return int 
 */
int main() {
  return frc::StartRobot<Robot<frc::Joystick>>();
}
#endif