#include "main.h"

double liftAvg(){
  return ((fabs(leftLift.get_position()) + (fabs(rightLift.get_position()))) / 2);
}
void liftReset(){
  leftLift.tare_position();
  rightLift.tare_position();
}

void liftMotors(int l, int r){
  leftLift = l;
  rightLift = r;
}
void lift(int height, int voltage){
  liftReset();
  int a = abs(height) / height;
  while(fabs(liftAvg()) < abs(height)){
    liftMotors(voltage * a, voltage * a);
    pros::delay(20);
  }
  liftMotors(12, 12);
}
