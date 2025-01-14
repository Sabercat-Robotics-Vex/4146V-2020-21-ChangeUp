#include "main.h"
#include "motors.hpp"
using namespace pros;

void disabled() {}


void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous();
void opcontrol() {
	Controller master(E_CONTROLLER_MASTER);


	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		//the int left represents the left joystick on the controller. Robot moves when the joystick is pushed forward or backwards.
		int right = master.get_analog(ANALOG_RIGHT_Y);
		//int right repersents the right joystick on the controller. Robot moves when the joystick is pushed forward or backwards.
		int liftSpeed = 100;
		//int liftSpeed is set at 100%
		leftDriveF = left;
		leftDriveB = left;
		//left motors on the drive train are controlled by the left joystick on the controller
		rightDriveF = right;
		rightDriveB = right;
		//right motors on the drive train are controlled by the right joystick on the controller

		if(master.get_digital(DIGITAL_R1) == 1){
			leftLift.move(100);
			rightLift.move(100);
		}
		//If the R1 button is pressed the motors on both sides of lift will move up at 100%

		else if(master.get_digital(DIGITAL_R2) == 1){
			leftLift.move(-50);
			rightLift.move(-50);
		}
		//If the R2 button is pressed instead then the motors on both sides of the lift will move down at -50%

		else{
			leftLift.move(12);
			rightLift.move(12);
		}
		//If neither buttons are pressed, then the lift will stay in place by the motors moving at 12%
		delay(20);

		if(master.get_digital(DIGITAL_L1) == 1){
		   	claw.move(100);
		}
		//If L1 button is pressed then the claw will open at 100%
	   else if(master.get_digital(DIGITAL_L2) == 1){
			  claw.move(-100);
		 }
		 //If the L2 button is pressed instead, then the claw will close at -100%
		 else{
			 claw.move(0);
		 }
		 //If neither L1 and L2 are pressed then the claw will not move
		 delay(20);
		}
}
