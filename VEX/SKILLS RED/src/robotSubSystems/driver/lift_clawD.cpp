#include "main.h"

double liftAvg(){
  return ((fabs(leftLift.get_position()) + (fabs(rightLift.get_position()))) / 2);
}
void liftReset(){
  leftLift.tare_position();
  rightLift.tare_position();
}

void lift_clawC(){
pros::Controller master(pros::E_CONTROLLER_MASTER);
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			leftLift.move(100);
			rightLift.move(100);
		}
		//If the R1 button is pressed the motors on both sides of lift will move up at 100%

		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			leftLift.move(-75);
			rightLift.move(-75);
		}
		//If the R2 button is pressed instead then the motors on both sides of the lift will move down at -50%

		else{
			leftLift.move (12);
			rightLift.move(12);
		}
		//If neither buttons are pressed, then the lift will stay in place by the motors moving at 12%
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        leftClaw.move(100);
        rightClaw.move(100);
    }
    //If L1 button is pressed then the claw will open at 100%
     else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        leftClaw.move(-100);
        rightClaw.move(-100);
     }
     //If the L2 button is pressed instead, then the claw will close at -100%
     else{
       leftClaw.move(0);
       rightClaw.move(0);
     }
     //If neither L1 and L2 are pressed then the claw will not move

     while(liftAvg() > 3700){
       leftLift.move(0);
       rightLift.move(0);
       pros::delay(20);
     }
     while(bumper.get_value()){
       liftReset();
     }

  }
