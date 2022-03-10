#include <frc/PIDSource.h>
#include <frc/PIDOutput.h>

#include "PidIO.h"
/**
 * @brief Sets the `PidIO` data.
 * <p> This is the data to be used with `frc::PIDController`
 * 
 */
void PidIO::setData(double data) {
    m_data = data;
}
/**
 * @brief Returns the `PidIO` data
 * 
 */
double PidIO::PIDGet() {
    return m_data;
}
/**
 * @brief Writes the `PidIO` data
 * 
 */
void PidIO::PIDWrite(double output) {
    m_output = output;
}
/**
 * @brief Returns the output that `frc::PIDController` return
 * 
 */
double PidIO::getOutput() {
    return m_output;
}