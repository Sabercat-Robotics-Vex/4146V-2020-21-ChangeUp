#include "main.h"
extern pros::Controller controller;
extern pros::Motor leftDriveF;
//RED GEARING CARTRIDGE
extern pros::Motor leftDriveB;
//RED GEARING CARTRIDGE
extern pros::Motor rightDriveF;
//RED GEARING CARTRIDGE
extern pros::Motor rightDriveB;
//RED GEARING CARTRIDGE
extern pros::Motor leftLift;
//RED GEARING CARTRIDGE
extern pros::Motor rightLift;
//RED GEARING CARTRIDGE
extern pros::Motor leftClaw;
//RED GEARING CARTRIDGE
extern pros::Motor rightClaw;
//RED GEARING CARTRIDGE
extern pros::ADIDigitalIn bumper;

void driveA(void);
void driveC(void);
void drive(int units, int voltage);
void lift_clawC(void);
void liftA(void);
void clawA(void);
void turn(int d, int voltage);
void claw(int oc);
void clawConstant(int v);
void lift(int height, int voltage);
void liftReset(void);
void midTower(void);
void highTower(void);
