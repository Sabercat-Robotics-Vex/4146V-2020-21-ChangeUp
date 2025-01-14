#include "main.h"

void midTower(){
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
    lift(1800, 75);
    while(bumper.get_value()){
      liftReset();
    }
  }
}
