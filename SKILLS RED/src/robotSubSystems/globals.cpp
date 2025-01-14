#include "main.h"
  pros::Motor leftDriveF(12, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftDriveB(14, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveF(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightDriveB(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1
  pros::Motor leftLift(19, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1 (18)
  pros::Motor rightLift(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  //RED GEARING CARTRIDGE 36:1 (19)
  pros::Motor leftClaw(16, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS); //Test claws
  //RED GEARING CARTRIDGE 36:1
  pros::Motor rightClaw(12, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
  pros::ADIDigitalIn bumper('A');
  pros::Controller controller(pros::E_CONTROLLER_MASTER);
