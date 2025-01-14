#include "main.h"
  pros::Motor leftDriveF(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftDriveB(2, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveF(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveB(10, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftLift(18, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightLift(19, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftClaw(13, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightClaw(12, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  pros::Controller controller(pros::E_CONTROLLER_MASTER);
