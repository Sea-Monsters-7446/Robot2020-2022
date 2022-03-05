#pragma once

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <atomic>
#include <utility>
#include <vector>

#include "SafeData.hpp"
#include "Vision.h"
#include "Utilities.h"

/**
 * @brief A class that detects circles in a given matrix and finds the distances of them
 * <p> Run this is a seperate thread or it will hang your execution thread
 * 
 */
struct VisionSense {
    public:
        /**
         * @brief Construct a new `VisionSense` object
         * 
         * @param data A `SafeData` object that stores the closest detected circles information
         * <p> 1st double is the x position
         * <p> 2nd double is the y position
         * <p> 3rd double is the distance from the robot the circle / ball is
         * <p> 4th double is the radius of the circle
         */
        VisionSense(SafeData<std::tuple<double, double, double, double>>& data);
        /**
         * @brief Detects circles in a matrix using provided color boundaries
         * 
         * @param bounds A const vector that stores vectors with the color bound data
         * <p> A '2d' vector is used here just in case some colors, like red for example, have high and low values
         * <p> (show up on the color spectrum on both sides) while others only show up once.
         * 
         * <p> If you want to detect a color that has a high and low values, you would create
         * <p> a vector that has two vectors in it. The first of which has the lower bounding data (In HSV format)
         * <p> and the second of which would have the higher of the two bounding data.
         * 
         * <p> If you only have one value, then you would just push one vector that has the bounding data into the 'base'
         * <p> vector instead of two.
         * 
         */
        void operator()(const std::vector<std::vector<unsigned char>>& bounds, SafeData<cv::Mat>& safeMatrix);
        /**
         * @brief Stops the `VisionSense` thread
         * 
         */
        void stop();
    private:
        std::vector<cv::Vec3f> circles;
        std::atomic_bool m_isRunning;
        SafeData<std::tuple<double, double, double, double>>& m_data;
};