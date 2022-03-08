#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <cameraserver/CameraServer.h>
#include <thread>
#include <tuple>

#include "SafeData.hpp"
#include "Autonomous.h"
/**
 * @brief Construct a new `Autonomous` object
 * 
 */
Autonomous::Autonomous(frc::DifferentialDrive& drive, frc::PWMVictorSPX& yeeter, SafeData<std::tuple<double, double, double, double>>& visionData, cs::UsbCamera& camera) :
    m_drive(drive),
    m_yeeter(yeeter),
    m_visionData(visionData),
    m_started(false),
    m_visionControl(m_visionData, frc::CameraServer::GetVideo(camera), frc::CameraServer::PutVideo("VisionSense", 640, 480))
{
    
}
/**
 * @brief Starts the `Autonomous` class
 * <p> Put all the code that you want to be executed at the start of Autonomous mode in this function
 * <p> Please Note: This function only gets called once everytime you change the mode to autonomous
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
 * <p> Put the code that you want to be executed when the Autonomous class stops in this function
 * 
 */
void Autonomous::stop() {
/**** Put all your code that needs to happen when the autonomous stops here ****/
    m_started = false;
    m_visionControl.stop();
}
/**
 * @brief Updates the `Autonomous` class
 * <p> Put all the code that you want to be executed while Autonomous mode is active
 * 
 */
void Autonomous::update() {
/**** Put all your autonomous code that needs to be periodicly updated here ****/
    m_visionControl.updateFrame();
    m_visionControl.putOutline();
    frc::SmartDashboard::PutNumber("Detected Circle X", std::get<0>(m_visionData.get()));
    frc::SmartDashboard::PutNumber("Detected Circle Y", std::get<1>(m_visionData.get()));
    frc::SmartDashboard::PutNumber("Detected Circle Distance", std::get<2>(m_visionData.get()));
    frc::SmartDashboard::UpdateValues();
}
/**
 * @brief Returns if the `Autonomous` class is started or not
 * 
 */
bool Autonomous::isStarted() {
    return m_started;
}