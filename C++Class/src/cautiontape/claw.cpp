#include "cautiontape/subsystems/claw.hpp"

using namespace cautionTape;

Claw::Claw() :
    claw(DIGITAL_SENSOR_PORT){
    closed = false;}

void Claw::close(){
    claw.set_value(true);
    closed = true;
}

void Claw::open(){
    claw.set_value(false);
    closed = false;
}
