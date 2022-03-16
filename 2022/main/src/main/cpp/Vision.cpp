#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include <cstdio>
#include <chrono>
#include <exception>
#include <atomic>
#include <vector>

#include "SafeData.hpp"
#include "Vision.h"
#include "Utilities.h"

/**
 * @brief Construct a new `VisionSense` object
 * 
 */
VisionSense::VisionSense(SafeData<std::tuple<double, double, double, double>>& data) :
    m_isRunning{false},
    m_data(data)
{

}
/**
 * @brief Detects circles in a matrix using provided color boundaries
 * 
 */ 
void VisionSense::operator()(const std::vector<std::vector<unsigned char>>& bounds, SafeData<cv::Mat>& safeMatrix) {
    cv::Mat accumMatrix;
    cv::Mat lowConvMatrix;
    cv::Mat highConvMatrix;
    m_isRunning = true;
    while (m_isRunning) {
        bool empty = true;
        int matrixRows = 0;

        // Converts image from BGR (RGB) to HSV (Hue, Saturation, Value) since it's easier to find different colors
        safeMatrix.processLocked([&accumMatrix, &empty, &matrixRows](cv::Mat& matrix){
            empty = matrix.empty();
            matrixRows = matrix.rows;
            if(!empty) {
                cv::cvtColor(matrix, accumMatrix, cv::ColorConversionCodes::COLOR_BGR2HSV);  
            }
        });

        if (!empty) {
            cv::inRange(accumMatrix, bounds.at(0), bounds.at(1), highConvMatrix);
            cv::inRange(accumMatrix, bounds.at(2), bounds.at(3), lowConvMatrix);
            cv::bitwise_or(lowConvMatrix, highConvMatrix, accumMatrix);
            // Finds circles
            cv::HoughCircles(accumMatrix, circles, cv::HoughModes::HOUGH_GRADIENT, 1, (matrixRows/4), 16, 19);
            std::pair<double, int> minDistancePoint = std::make_pair(std::numeric_limits<double>::max(), -1);

            for(unsigned int times = 0; times < circles.size(); times++) {
                cv::Vec3i c = circles.at(times);
/*
                // circle center
                cv::circle(fullMatrix, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);

                // circle outline
                int radius = c[2];
                cv::circle(fullMatrix, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
*/
                // Finds the "distance of the circles from the camera and keeps track of the closest one"
                std::pair<double, int> curPair = std::make_pair(Utilities::findDistanceFromObject(1, 2, 180, Utilities::findPitchFromObject(c[1], Utilities::LIFECAM_VERTICAL_FOV)), times);
                if(minDistancePoint.first > curPair.first) {
                    minDistancePoint = curPair;
                }
            }

            if(minDistancePoint.second != -1) {
                cv::Vec3i closest = circles.at(minDistancePoint.second);
                double distanceOfClosestCircle = minDistancePoint.first;
                m_data.set(std::make_tuple(closest[0], closest[1], distanceOfClosestCircle, closest[2]));
            }
        }
    }
}

/**
 * @brief Stops the `VisionSense` thread
 * 
 */
void VisionSense::stop() {
    m_isRunning = false;
}