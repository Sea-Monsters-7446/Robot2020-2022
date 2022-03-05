#include <tuple>
#include <frc/DriverStation.h>
#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include "Vision.h"
#include "VisionControl.h"
#include "SafeData.hpp"

//#define VISION_TESTING

/**
 * @brief Construct a new `VisionController` object
 * 
 */
VisionController::VisionController(SafeData<std::tuple<double, double, double, double>>& data, cs::CvSink sink, cs::CvSource output) :
    m_data(data),
    m_outputMat(cv::Mat(480, 640, CV_8UC3)),
    m_visionSense(m_data),
    m_sink(sink),
    m_output(output)
{
    m_safeMatrix.processLocked([](cv::Mat& matrix) -> void {
        matrix.create(640, 480, CV_8UC3);
    });
}
/**
 * @brief Starts a new thread with the `VisionSense` object in it
 * 
 */
int VisionController::start() {
#ifdef VISION_TESTING
    m_safeMatrix.processLocked([](cv::Mat& matrix) -> void {
        matrix = cv::imread("/Users/robotics-mac-0/Pictures/Dots.png", cv::IMREAD_COLOR);
    });
#endif
    if (frc::DriverStation::GetAlliance() == frc::DriverStation::Alliance::kRed) {
        m_visionThread = std::thread([this]() -> void {
            m_visionSense(m_boundsRed, m_safeMatrix);
        });
        return 1;
    }
    else if (frc::DriverStation::GetAlliance() == frc::DriverStation::Alliance::kBlue) {
        m_visionThread = std::thread([this]() -> void {
            m_visionSense(m_boundsBlue, m_safeMatrix);

        });
        return 1;
    }
    else {
        // In theory this should only occur if frc::DriverStation::getAlliance() returns kInvalid
        // To which I have no clue when this would happen. Maybe when the robot is in disabled?
        return -1;
    }
}
/**
 * @brief Stops the thread from executing
 * 
 */
 void VisionController::stop() {
    m_visionSense.stop();
}
/**
 * @brief Updates the matrix using the given `cs::CvSink` object in the constructor of `VisionController`
 * 
 */
void VisionController::updateFrame() {
#ifndef VISION_TEST
    m_safeMatrix.processLocked([this](cv::Mat& matrix) -> void {
        if(m_sink.GrabFrame(matrix) == 0) {
            m_output.NotifyError(m_sink.GetError());
        }
    });
#endif
}

/**
 * @brief Draws the outline and center of the circle onto the a copy of the main image and sends it to the `cs::CvSource` object
 * 
 */
void VisionController::putOutline(bool overlayOriginal) {
    // Circle center coordinates
    cv::Point center = cv::Point(std::get<0>(m_data.get()), std::get<1>(m_data.get()));
    // Draws the center
    cv::circle(m_outputMat, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);
    // Draws the outline
    int radius = std::get<3>(m_data.get());
    cv::circle(m_outputMat, center, radius, cv::Scalar(255, 0, 0), 3, cv::LINE_AA);
    if (overlayOriginal) {
        m_safeMatrix.processLocked([this](cv::Mat& matrix) -> void {
            cv::addWeighted(matrix, 1, m_outputMat, 1, 0.5, m_outputMat);
        });
    }
#ifdef VISION_TESTING
    cv::imwrite("/Users/robotics-mac-0/Desktop/image.png", m_outputMat);
#endif
    m_output.PutFrame(m_outputMat);
}