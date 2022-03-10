#pragma once

#include <frc/PIDSource.h>
#include <frc/PIDOutput.h>
/**
 * @brief A class that is used to define your own PID data to be used with `frc::PIDController`
 * 
 */
class PidIO : public frc::PIDSource, public frc::PIDOutput {
public:
    /**
     * @brief Sets the `PidIO` data.
     * <p> This is the data to be used with `frc::PIDController`
     * 
     * @param data 
     */
    void setData(double data);
    /**
     * @brief Returns the `PidIO` data
     * 
     * @return double 
     */
    double PIDGet() override;
    /**
     * @brief Writes the `PidIO` data
     * 
     */
    void PIDWrite(double output) override;
    /**
     * @brief Returns the output that `frc::PIDController` return
     * 
     */
    double getOutput();
    
private:
    double m_data;
    double m_output;
};