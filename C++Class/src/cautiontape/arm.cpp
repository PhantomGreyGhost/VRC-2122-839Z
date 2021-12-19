#include "cautiontape/subsystems/arm.hpp"

using namespace cautionTape;

Arm::Arm() :
    leftArmMotor(LEFTARMMOTOR, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees),
    rightArmMotor(RIGHTARMMOTOR, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees){
    armMove = std::dynamic_pointer_cast<AsyncPosPIDController>(AsyncPosControllerBuilder()
        .withMotor({leftArmMotor, rightArmMotor})
        .withGains({1, 0, 0, 0})
        .build());
    };

void Arm::up(){
    leftArmMotor.moveVelocity(100);
    rightArmMotor.moveVelocity(100);
}

void Arm::down(){
    leftArmMotor.moveVelocity(-100);
    rightArmMotor.moveVelocity(-100);
}

void Arm::stop(){
    leftArmMotor.moveVelocity(0);
    rightArmMotor.moveVelocity(0);
}

void Arm::moveLocation(){

}
