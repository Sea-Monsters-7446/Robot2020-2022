#pragma once

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tuple>
#include <thread>
#include <vector>

#include "Vision.h"
#include "SafeData.hpp"
/**
 * @brief A class that controls the `VisionSense` class
 * 
 */
class VisionController {
    public:
    /**
     * @brief Construct a new `VisionController` object
     * 
     * @param data The data that it creates. A `SafeData` with four templated arguments of type doubles
     * @param sink The `cs::CvSink` object to get the frame
     * @param output The `cs::CvSource` object to output the frame to
     */
    VisionController(SafeData<std::tuple<double, double, double, double>>& data, cs::CvSink sink, cs::CvSource output);
    /**
     * @brief Starts a new thread with the `VisionSense` object in it
     * 
     */
    int start();
    /**
     * @brief Stops the thread from executing
     * 
     */
    void stop();
    /**
     * @brief Updates the matrix using the given `cs::CvSink` object in the constructor of `VisionController`
     * 
     */
    void updateFrame();
    /**
     * @brief Draws the outline and center of the circle onto the a copy of the main image and sends it to the `cs::CvSource` object
     * @param overlayOrigin Optional. Set this to true if you want to overlay the outline of the closest detected circle on the original image
     * 
     */
    void putOutline(bool overlayOriginal = true);

    private:
    SafeData<cv::Mat> m_safeMatrix;
    SafeData<std::tuple<double, double, double, double>>& m_data;
    cv::Mat m_outputMat;
    VisionSense m_visionSense;
    std::thread m_visionThread;
    cs::CvSink m_sink;
    cs::CvSource m_output;
    // Upper and lower HSV value bounds for the color red
    const std::vector<std::vector<unsigned char>> m_boundsRed = {{170, 50, 50}, {180, 255, 255}, {0, 50, 50}, {10, 255, 255}};
    // Upper and lower HSV value bounds for the color blue
    const std::vector<std::vector<unsigned char>> m_boundsBlue = {{147, 115, 133}};
};
