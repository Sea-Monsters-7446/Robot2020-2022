#include "Vision.h"

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <atomic>
#include <utility>
#include "SafeData.hpp"
/**
 * @brief Construct a new `VisionSense` object
 * 
 * @param data 
 */
VisionSense::VisionSense(SafeData<std::tuple<double, double, double>>& data) :
    m_isRunning{false},
    m_data(data)
{

}
/**
 * @brief Does some stuff with the camera output to detect balls
 * 
 */
void VisionSense::operator()() {
    cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture(0);
    camera.SetResolution(640, 480);
    cs::CvSink sync = frc::CameraServer::GetVideo();
    cs::CvSource output = frc::CameraServer::PutVideo("VisionSense", 640, 480);
    cv::Mat matrix;
    m_isRunning = true;
    while (m_isRunning) {
        if (sync.GrabFrame(matrix) == 0) {
            output.NotifyError(sync.GetError());
            continue;
        }

        // Say the X and Y are the coordinate of the center of the closest ball from [-1, -1] to [1, 1]
        double closestCircleX = 0.0;
        double closestCircleY = 0.0;
        double closestCircleDistance = 0.0;

        // Use openCV to identify circles (hough algorithm)
        // see https://docs.opencv.org/3.4/d4/d70/tutorial_hough_circle.html

        // Then calculate the distance of the circle based on the known radius of the ball
        // Calculate the X, and Y of where the center of the ball in the viewport.

        // Set the ball information
        m_data.set(std::make_tuple(closestCircleX, closestCircleY, closestCircleDistance));
        output.PutFrame(matrix);
    }
}
/**
 * @brief Stops
 * 
 */
void VisionSense::stop() {
    m_isRunning = false;
}