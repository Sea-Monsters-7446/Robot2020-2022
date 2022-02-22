#pragma once
#include "Vision.h"
#include "SafeData.hpp"
#include <tuple>
#include <thread>
/**
 * @brief A class that controls the `VisionSense` class
 * 
 */
class VisionController {
    public:
    /**
     * @brief Construct a new `VisionController` object
     * 
     * @param data The data that it creates. A std::tuple with three arguments of type doubles
     */
    VisionController(SafeData<std::tuple<double, double, double>>& data);
    /**
     * @brief Starts a new thread with the `VisionSense` object in it
     * 
     */
    void start();
    /**
     * @brief Stops the thread from executing
     * 
     */
    void stop();

    private:
    SafeData<std::tuple<double, double, double>>& m_data;
    VisionSense m_visionSense;
    std::thread m_visionThread;
};
