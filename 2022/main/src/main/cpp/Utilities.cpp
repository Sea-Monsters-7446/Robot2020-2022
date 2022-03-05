#include <utility>
#include <cmath>

#include "Utilities.h"
/**
 * @brief Finds the pitch of the object from the camera
 * 
 */
double Utilities::findPitchFromObject(double objectConvertedAiming_y, double verticalFov) {
    return (objectConvertedAiming_y / 2) * verticalFov;
}
/**
 * @brief Finds the yaw of the object from the camera
 * 
 */
double Utilities::findYawFromObject(double objectConvertedAiming_x, double horizontalFov) {
    return (objectConvertedAiming_x / 2) * horizontalFov;
}
/**
 * @brief Converts an x position from a coordinate system to a -1 to 1 range
 * 
 */
double Utilities::convertToAiming_x(double pixel_x, double resolution_x) {
    return (pixel_x - (resolution_x / 2)  / (resolution_x / 2));
}
/**
 * @brief Converts a y position from a coordinate system to a 1 to -1 value
 * 
 */
double Utilities::convertToAiming_y(double pixel_y, double resolution_y) {
   
    return (pixel_y - (resolution_y / 2) / (resolution_y / 2));
}
/**
 * @brief Finds the distance away from an object the camera is
 * 
 */
double Utilities::findDistanceFromObject(double heightOfObject, double heightOfCamera, double angleOfCamera, double pitchOfObject) {
    return ((heightOfObject - heightOfCamera) / (tan(angleOfCamera + pitchOfObject)));
}
