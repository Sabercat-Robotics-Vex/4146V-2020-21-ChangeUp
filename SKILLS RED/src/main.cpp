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

void autonomous() {
		//drive = +(foward) , -(backwards)
		//turn = +(left) , -(right)
		//lift limit 3700
		leftLift = -5;
		drive(1900, 70);
	  drive(-2100, 70);
		turn(-90, 80);
		drive(600, 70);
		claw(1);
		turn(-90, 80);
		drive(900, 70);
		lift(2000, 70);
		drive(900, 70);
		claw(0);
		clawConstant(0);
		drive(-1800, 50);
		lift(-1900, 70);
		turn(90, 80);
		drive(1600, 50);
		lift(500, 50);
		clawConstant(80);
		delay(100);
		drive(-2600, 70);
		turn(110, 70);
		drive(2300, 70);
		lift(-300,30);
		clawConstant(-20);
		drive(-800,50);
		delay(300);
	}

void opcontrol() {
	liftReset();
	while (true) {
		driveC();
		lift_clawC();
		midTower();
		delay(20);
		}
}
