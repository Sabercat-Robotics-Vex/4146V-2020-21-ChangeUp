#include "main.h"

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
  double m = d * 8.5;
  double turn = fabs(m) / m;
  while(fabs(avgDriveL()) < fabs(m)){
    driveSetup(voltage * -turn, voltage * turn);
    pros::delay(5);
  }
  driveSetup(turn * -10, -turn * -10);
  pros::delay(50);
  driveSetup(0, 0);
}
