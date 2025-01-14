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
  return ((leftDriveF.get_position() +
          leftDriveB.get_position()) / 2);
}

double avgDriveR(){
  return ((rightDriveF.get_position() +
          rightDriveB.get_position()) / 2);
}

double avgDrive(){
  return avgDriveR() + avgDriveL();
}

void drive(int units, int voltage){
  driveReset();
  int direction = abs(units) / units;
  while(fabs(avgDrive()) / 2 < abs(units)){
    driveSetup(voltage * direction, voltage * direction);
    pros::delay(3);
  }

  driveSetup(-10 * direction, -10 * direction);
  pros::delay(50);

  driveSetup(0, 0);
}

void turn(int d, int voltage){
  driveReset();
  int m = d * 7;
  int turn = abs(m) / m;
  while(fabs(avgDriveL()) < abs(m)){
    driveSetup(voltage * -turn, voltage * turn);
    pros::delay(5);
  }
  driveSetup(turn * -10, -turn * -10);
  pros::delay(50);
  driveSetup(0, 0);
}
