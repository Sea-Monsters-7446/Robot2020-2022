#pragma once

#include <utility>
#include <cmath>

class Utilities {
    public:
    /**
     * @brief Construct a new `Utilities` object
     * 
     */
    Utilities();
    /**
     * @brief Finds the pitch of the object from the camera
     * 
     * @param objectConvertedAiming_y The y position of the object converted to a 1 to -1 range using `Utilities::convertToAiming_x` and `Utilities::convertToAiming_y`
     * @param verticelFov The vertical Field of view of the camera. For the Microsoft LifeCam it is `Utilities::LIFECAM_VERTICAL_FOV`
     * @return double 
     */
    static double findPitchFromObject(double objectConvertedAiming_y, double verticelFov);
    /**
     * @brief Finds the yaw of the object from the camera
     * 
     * @param objectConvertedAiming_x The x position of the object converted to a -1 to 1 range using `Utilities::convertToAiming_x` and `Utilities::convertToAiming_y`
     * @param horizontalFov The horizontal Field of view of the camera. For the Microsoft LifeCam it is `Utilities::LIFECAM_HORIZONTAL_FOV`
     * @return double 
     */
    static double findYawFromObject(double objectConvertedAiming_x, double horizontalFov);
    /**
     * @brief Converts an x position from a coordinate system to a -1 to 1 range
     * 
     * @param pixel_x The x position in the matrix
     * @param resolution_x The width of the matrix
     * @return double 
     */
    static double convertToAiming_x(double pixel_x, double resolution_x);
    /**
     * @brief Converts a y position from a coordinate system to a 1 to -1 value
     * 
     * @param pixel_y The y position in the matrix
     * @param resolution_y The height of the matrix
     * @return double 
     */
    static double convertToAiming_y(double pixel_y, double resolution_y);
    /**
     * @brief Finds the distance away from an object the camera is
     * 
     * @param heightOfObject The physical height of the object
     * @param heightOfCamera The physical height of the camera
     * @param angleOfCamera The angle of the camera
     * @param pitchOfObject The pitch of the object
     * @return double 
     */
    static double findDistanceFromObject(double heightOfObject, double heightOfCamera, double angleOfCamera, double pitchOfObject);

    /**
     * @brief The Microsoft LifeCam horizontal Field of View
     * 
     */
    static constexpr double LIFECAM_HORIZONTAL_FOV = 61;
    /**
     * @brief The Microsoft LifeCam vertical Field of View
     * 
     */
    static constexpr double LIFECAM_VERTICAL_FOV = 34.3;
    /**
     * @brief The Microsoft LifeCam diagonal Field of View
     * 
     */
    static constexpr double LIFECAM_DIAGONAL_FOV = 68.5;
};