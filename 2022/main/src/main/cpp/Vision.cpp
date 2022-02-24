#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <frc/smartdashboard/SmartDashboard.h>
#include <chrono>
#include <atomic>
#include <vector>
#include "SafeData.hpp"
#include "Macros.h"
#include "Vision.h"

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
    std::vector<cv::Vec3f> circles;
    std::vector<cv::Mat> rgbChannels;
#ifdef VISION_TEST
    cv::Mat fullMatrix = cv::imread("/Users/robotics-mac-0/Documents/Test.png");
#else
    cv::Mat fullMatrix;
#endif
    m_isRunning = true;
    while (m_isRunning) {
#ifndef VISION_TEST
        if (sync.GrabFrame(fullMatrix) == 0) {
            output.NotifyError(sync.GetError());
            continue;
        }
#endif
        cv::split(fullMatrix, rgbChannels);
        cv::HoughCircles(rgbChannels.at(0), circles, cv::HoughModes::HOUGH_GRADIENT, 1, ((rgbChannels.at(1).rows) / 4), 50, 30);
        std::pair<double, int> minDistancePoint = std::make_pair(std::numeric_limits<double>::max(), -1);
        for(unsigned int times = 0; times < circles.size(); times++) {
            cv::Vec3i c = circles.at(times);
            cv::Point center = cv::Point(c[0], c[1]);
            // circle center
            cv::circle(fullMatrix, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);
            // circle outline
            int radius = c[2];
            cv::circle(fullMatrix, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
            std::pair<double, int> curPair = std::make_pair(FIND_DIST(1, 2, 180, FIND_PITCH_FROM_OBJECT(c[1], LIFECAM_VERT_FOV)), times);
            if(minDistancePoint.first > curPair.first) {
                minDistancePoint = curPair;
            }
        }
        if(minDistancePoint.second != -1) {
            cv::Vec3i closest = circles.at(minDistancePoint.second);
            double distanceOfClosestCircle = minDistancePoint.first;
            m_data.set(std::make_tuple(closest[0], closest[1], distanceOfClosestCircle));
        }
        output.PutFrame(fullMatrix);
        circles.clear();
        rgbChannels.clear();
    }
}
/**
 * @brief Stops
 * 
 */
void VisionSense::stop() {
    m_isRunning = false;
}