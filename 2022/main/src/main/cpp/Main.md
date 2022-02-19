#include <Definitions.h>
#include <Controller.h>

#ifndef RUNNING_FRC_TESTS   // I need this or else it'll fight over main functions

void Test() {
    return 0
}

int main() {
    Controller Test[2];
    Test[1].SetPort(1);
    Test[1].Triggers[0] = &Test;
    
    return 0;
}

#endif
