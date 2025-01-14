#include "main.h"

void clawReset(){

  leftClaw.tare_position();
  rightClaw.tare_position();
}

double clawAvg(){
  return (fabs(leftClaw.get_position()) + fabs(rightClaw.get_position()) / 2);
}

void claw(int oc){
  clawReset();
  while(oc == 1 && clawAvg() < 700){
    leftClaw = 75;
    rightClaw = 75;
    pros::delay(20);
  }
  clawReset();
  while(oc == 0 && clawAvg() < 700){
    leftClaw = -75;
    rightClaw = -75;
    pros::delay(20);
  }
}

void clawConstant(int v){
  leftClaw = v;
  rightClaw = -v;
  pros::delay(20);
}
