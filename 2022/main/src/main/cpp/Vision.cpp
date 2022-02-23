#include "Vision.h"
#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include <atomic>
#include <utility>
#include <vector>
#include <cstdio>
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
    cs::CvSource output = frc::CameraServer::PutVideo("VisionSense Detected Circles", 640, 480);
    cv::Mat fullMatrix;
    std::vector<cv::Mat> rgbChannels;
    m_isRunning = true;
    while (m_isRunning) {
        if (sync.GrabFrame(fullMatrix) == 0) {
            output.NotifyError(sync.GetError());
            continue;
        }
        std::vector<cv::Vec3f> circles;
        cv::split(fullMatrix, rgbChannels);
        cv::HoughCircles(rgbChannels.at(1), circles, cv::HoughModes::HOUGH_STANDARD, 1, ((rgbChannels.at(1).rows) / 4), 200, 100);
        for(unsigned int times = 0; times < circles.size(); times++) {
            cv::Vec3i c = circles[times];
            cv::Point center = cv::Point(c[0], c[1]);
            // circle center
            cv::circle(fullMatrix, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);
            // circle outline
            int radius = c[2];
            cv::circle(fullMatrix, center, radius, cv::Scalar(255,0,255), 3, cv::LINE_AA);
        }
        output.PutFrame(fullMatrix);
    }
}
/**
 * @brief Stops
 * 
 */
void VisionSense::stop() {
    m_isRunning = false;
}