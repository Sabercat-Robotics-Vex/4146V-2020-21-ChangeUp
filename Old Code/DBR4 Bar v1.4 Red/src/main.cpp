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
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	drive(1500, 70);
	controller.set_text(1, 1, "LETS GOOOOOO");
	drive(-500, 70);
	clawConstant(2, 2);
	turn(-90, 80);
	drive(2500, 50);
	clawConstant(50, 50);
	pros::delay(300);
	controller.set_text(1, 1, "Oh yeahhhhhh");
	lift(500, 50);
	drive(-2000, 50);
	turn(90, 80);
	drive(800, 70);
	lift(-400,50);
	clawConstant(-20, -20);
	drive(-400, 40);
	clawConstant(0, 0);
	controller.set_text(2, 1, "You suck");
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
