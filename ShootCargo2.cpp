#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/constraint/MaxVelocityConstraint.h>

// Class definition
class TrajShoot : public frc::Trajectory {
    public:
     void TotalTime() override {units::second_t}
     void SetStartVelocity() override {units::meters_per_second_t}
     void SetEndVelocity() override {units::meters_per_second_t}
    private:
     frc::TrajectoryConfig{};
     frc::MaxVelocityConstraint{};
};

// For statement
int main() {
    for (i = 0; i < /*insert number here*/; i++) {
        
    }
}