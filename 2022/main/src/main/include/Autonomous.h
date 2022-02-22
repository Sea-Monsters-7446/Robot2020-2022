#pragma once
#include <frc/drive/DifferentialDrive.h>
#include "VisionControl.h"
#include "SafeData.hpp"
#include <tuple>
/**
 * @brief A class that handles autonomous functionallity
 * 
 */
class Autonomous {
    public:
        /**
         * @brief Construct a new `Autonomous` object
         * 
         * @param drive The `DifferentialDrive` object
         * @param visionData The `SafeData` object
         */
        Autonomous(frc::DifferentialDrive& drive, SafeData<std::tuple<double, double, double>>& visionData);
        /**
         * @brief Starts the `Autonomous` class
         * 
         * @return int 
         */
        int start();
        /**
         * @brief Stops the `Autonomous` class
         * 
         */
        void stop();
        /**
         * @brief Updates the `Autonomous` class
         * 
         */
        void update();
        /**
         * @brief Returns if the `Autonomous` class is started or not
         * 
         * @return true 
         * @return false 
         */
        bool isStarted();

    private:
        frc::DifferentialDrive& m_drive;
        bool m_started;
        SafeData<std::tuple<double, double, double>>& m_visionData;
        // Declare your autonomous classes here
        VisionController m_visionControl;
};