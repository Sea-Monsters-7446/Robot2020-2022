#pragma once

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <atomic>
#include <utility>
#include "SafeData.hpp"
#include "Vision.h"

/**
 * @brief A class that takes input from a camera and detects stuff
 * 
 */
struct VisionSense {
    public:
        /**
         * @brief Construct a new VisionSense object
         * 
         * @param data A reference to the variable you want to store the data in
         * <p> Recommended to use `SafeData` To create thread safe data
         */
        VisionSense(SafeData<std::tuple<double, double, double>>& data);
        /**
         * @brief Does some stuff with the camera output to detect balls
         * 
         */
        void operator()();
        /**
         * @brief Stops
         * 
         */
        void stop();
    private:
        std::atomic_bool m_isRunning;
        SafeData<std::tuple<double, double, double>>& m_data;
};