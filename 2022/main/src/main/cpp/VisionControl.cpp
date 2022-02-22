#include "Vision.h"
#include "VisionControl.h"
#include "SafeData.hpp"
#include <tuple>
/**
 * @brief Construct a new `VisionController` object
 * 
 * @param data 
 */
VisionController::VisionController(SafeData<std::tuple<double, double, double>>& data) :
    m_data(data),
    m_visionSense(m_data)
{

}
/**
 * @brief Starts a new thread with the `VisionSense` object in it
 * 
 */
void VisionController::start() {
    m_visionThread = std::thread([this]() -> void {
        m_visionSense();
    });
}
/**
 * @brief Stops the thread from executing
 * 
 */
 void VisionController::stop() {
    m_visionSense.stop();
}

