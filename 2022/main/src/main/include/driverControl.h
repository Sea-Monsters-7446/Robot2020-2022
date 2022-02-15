#include "buttonState.h"
#include "Robot.h"

#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>

#pragma once
/**
 * @brief A class that is used to control and update the drive stuff you know (;
 * 
 */
class driverController {
    public:
        /**
         * @brief Construct a new driverController object
         * 
         * @param drive The drive control object
         */
        driverController(frc::DifferentialDrive& drive);
        /**
         * @brief Updates the position of the wheels
         * 
         */
        void update(double x, double y);
    private:
        /**
         * @brief Update the position and movement of the wheels
         * 
         */
        void updateWheels();
        /**
         * @brief Struct that keeps track of the joysticks X and Y position and stores it
         * 
         */
        struct m_joystickAxisList {
            double x;
            double y;
        };

        m_joystickAxisList joystickAxis;

        frc::DifferentialDrive& m_drive;
};