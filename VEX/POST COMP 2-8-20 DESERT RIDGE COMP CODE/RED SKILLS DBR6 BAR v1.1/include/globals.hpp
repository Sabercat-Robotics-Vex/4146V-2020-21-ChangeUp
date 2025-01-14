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

extern pros::Motor rightClaw;
extern pros::ADIDigitalIn limit;

void driveC(void);
void lift_clawC(void);
void driveA(void);
void liftA(void);
void clawA(void);
void drive(int units, int voltage);
void turn(int d, int voltage);
void claw(int oc);
void clawConstant(int l, int r);
void lift(int height, int voltage);
void liftReset(void);
