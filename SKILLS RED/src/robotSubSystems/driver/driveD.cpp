#include "main.h"

void driveC(){
  pros::Controller master(pros::E_CONTROLLER_MASTER);

    int left = master.get_analog(ANALOG_LEFT_Y);
    //the int left represents the left joystick on the controller. Robot moves when the joystick is pushed forward or backwards.
    int right = master.get_analog(ANALOG_RIGHT_Y);
    //int right repersents the right joystick on the controller. Robot moves when the joystick is pushed forward or backwards.
    //int liftSpeed is set at 100%
    leftDriveF = left;
    leftDriveB = left;
    //left motors on the drive train are controlled by the left joystick on the controller
    rightDriveF = right;
    rightDriveB = right;
}
