#include <stdio.h>

#define BUTTONS_MAX 4

typedef void (*func)(void);
// Define function easier

typedef struct Joystick {
    func Triggers[BUTTONS_MAX];
    func UpdateAxis;
} joystick;
// Also define a joystick

void TestFunc() {
    printf("I am a test function for testing is what I am\n");
}

int main() {
    joystick Test;
    Test.Triggers[0] = &TestFunc;   // An explicit pointer to the function is NOT needed
    
    (*Test.Triggers[0])();  // You NEED to call it like this
    return 0;
}
