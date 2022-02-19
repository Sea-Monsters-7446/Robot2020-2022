#pragma once

#include <frc/GenericHID.h>
#include <stdexcept>
#include "Definitions.h"

typedef void (*func)();

class Controller {
    public:
        func AxisUpdate;                // This is the trigger that'll run when the axis is updated
        func Triggers[DEF_BUTTON_MAX];  // Functions that'll run on button presses
    
        int GetPort() {                 // Since this is small, I'll have it like this
            return Port;
        }
    
        void SetPort(int NewPort) {  // Because I always want Port and HID to match, I need this function
            if (NewPort < 0) {
                throw std::invalid_argument("Port cannot be below 0");
            }
            
            Port = NewPort;
            HID_Dev = frc::GenericHID(Port);
        }
    
        void Update() { // This should be placed in a loop
            int i;
            for (i = 0; i < DEF_BUTTON_MAX; i ++) {
                if (HID_Dev.GetRawButtonPressed(i)) {
                    (*Triggers[i])();
                }
            }
        }
    
    private:
        int Port = 0;
        class frc::GenericHID HID_Dev = frc::GenericHID(0); // Have to set this or else it'll complain about constructors
};





