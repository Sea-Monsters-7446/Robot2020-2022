#include <frc/drive/DifferentialDrive.h>
#include "SafeData.hpp"
#include "Autonomous.h"
#include <thread>
#include <tuple>
/**
 * @brief Construct a new `Autonomous` object
 * 
 */
Autonomous::Autonomous(frc::DifferentialDrive& drive, SafeData<std::tuple<double, double, double>>& visionData) :
    m_drive(drive),
    m_started(false),
    m_visionData(visionData),
    m_visionControl(m_visionData)
{

}
/**
 * @brief Starts the `Autonomous` class
 * 
 */
int Autonomous::start() {
    if (m_started) {
        return -1;
    }
    m_started = true;
    m_visionControl.start();
    return 1;
}
/**
 * @brief Stops the `Autonomous` class
 * 
 */
void Autonomous::stop() {
    m_started = false;
    m_visionControl.stop();
}
/**
 * @brief Updates the `Autonomous` class
 * 
 */
void Autonomous::update() {
// Put all your autonomous code that needs to be periodicly updated here //

}
/**
 * @brief Returns if the `Autonomous` class is started or not
 * 
 */
bool Autonomous::isStarted() {
    return m_started;
}