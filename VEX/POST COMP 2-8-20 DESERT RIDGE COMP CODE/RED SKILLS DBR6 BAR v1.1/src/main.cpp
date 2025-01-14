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
	controller.set_text(1, 1, "LETS GOOOOOO");
  drive(-2100, 70);
	turn(-90, 80);
	drive(600, 70);
	claw(1);
	turn(-90, 80);
	drive(900, 70);
	controller.set_text(1, 1, "Checkpoint 2");
	lift(2400, 70);
	drive(900, 70);
	claw(0);
	clawConstant(0 ,0);
	drive(-1500, 50);
	lift(-1900, 70);
	turn(90, 80);
	drive(1550, 50);
	//lift(400, 50);
	clawConstant(80, 80);
	delay(200);
	drive(-2600, 70);
	turn(110, 70);
	drive(2500, 70);
	lift(-300, 30);
	clawConstant(-20, -20);
	drive(-800,50);
	delay(300);
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
