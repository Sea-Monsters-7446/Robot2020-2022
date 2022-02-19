#include "Vision.h"

#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <atomic>
#include <utility>
#include "SafeData.hpp"

VisionSense::VisionSense(SafeData<std::tuple<double, double, double>>& data) :
    m_isRunning{false},
    m_data(data)
{

}

void VisionSense::operator()() {
    cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture();
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
        output.PutFrame(matrix);
    }
}