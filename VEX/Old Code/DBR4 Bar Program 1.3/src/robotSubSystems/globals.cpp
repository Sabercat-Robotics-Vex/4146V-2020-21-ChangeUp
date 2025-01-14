#include "main.h"
  pros::Motor leftDriveF(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftDriveB(2, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveF(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveB(10, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftLift(16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightLift(17, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftClaw(12, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightClaw(13, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  pros::Controller controller(pros::E_CONTROLLER_MASTER);
