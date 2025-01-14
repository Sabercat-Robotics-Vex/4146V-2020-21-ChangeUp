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

double avgDriveL(){
  return (fabs(leftDriveF.get_position() +
          fabs(leftDriveB.get_position())) / 2);
}

double avgDriveR(){
  return (fabs(rightDriveF.get_position() +
          fabs(rightDriveB.get_position())) / 2);
}

void forward(int units, int voltage){
  driveReset();
  int direction = abs(units) / units;
  while(/*avgDriveL() +avgDriveR()) / 2*/ leftDriveF.get_position() < abs(units)){
    driveSetup(voltage * direction, voltage * direction);
    pros::delay(5);
  }

  driveSetup(-10 * direction, -10 * direction);
  pros::delay(50);

  driveSetup(0, 0);
}

void turn(int dl, int dr, int voltage){
  driveReset();

}
