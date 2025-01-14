#include "main.h"
using namespace pros;

void disabled() {}


void competition_initialize() {
	lcd::initialize();
	lcd::set_text(1, "Cats");

	leftDriveF.set_brake_mode(E_MOTOR_BRAKE_COAST);
	leftDriveB.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightDriveF.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightDriveB.set_brake_mode(E_MOTOR_BRAKE_COAST);
	leftClaw.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	rightClaw.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	leftLift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternativ
 \\\\\\\\\\\\\ely, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	//drive = +(foward) , -(backwards)
	//turn = +(left) , -(right)
	leftLift = -5;
	drive(1900, 70);
	//drive forward pushing preload cube into the goal
  drive(-2100, 70);
	//drive backward away from preload cube
	turn(45, 80);
	//turn 45 degrees left, toward corner cube
	drive(1600, 70);
	//drive forward toward cube
	clawConstant(70, 70);
	//claw closes around cube, claw is constantly providing tension to cube
	lift(300, 40);
	//lift slightly so cube doesn't drag
	drive(-1400, 70);
	//drive backwards
	turn(-45, 80);
	//turn right 45 degrees
	drive(1900, 50);
	//drive forwards
	clawConstant(-30, -30);
	//slowly releases the cube so claw doesn't knock preload cube
	delay(200);
	//delay to give claw time
	drive(-800,50);
	//robot backaway from cube without touching anything
}
//lift limit 3700
void opcontrol() {
	liftReset();
	while (true) {
		driveC();
		lift_clawC();
		delay(20);
		}
}
