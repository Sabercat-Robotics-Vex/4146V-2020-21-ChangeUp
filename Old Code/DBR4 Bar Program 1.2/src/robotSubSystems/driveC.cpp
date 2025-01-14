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
void driveReset(){
  leftDriveF.tare_position();
  leftDriveB.tare_position();
  rightDriveF.tare_position();
  rightDriveB.tare_position();
}
void driveSetup(int l, int r){
  leftDriveF = l;
  leftDriveB = l;
  rightDriveF = r;
  rightDriveB = r;
}

double avgDriveEnc(){
  return (fabs(leftDriveF.get_position()) +
         fabs(leftDriveB.get_position()) +
         fabs(rightDriveF.get_position()) +
         fabs(rightDriveB.get_position())) / 4;
}

void driveA(int units, int voltage){
  int direction = abs(units) / units;
  driveReset();

  while(avgDriveEnc() < abs(units)){
    driveSetup(voltage * direction, voltage * direction);
    pros::delay(10);
  }

  driveSetup(-10 * direction, -10 * direction);
  pros::delay(10);

  driveSetup(0,0);
}
