#include "cautiontape/subsystems/chassis.hpp"

using namespace cautionTape;

Chassis::Chassis() :
    frontLeftMotor(FRONTLEFTMOTOR, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees),
    frontRightMotor(FRONTRIGHTMOTOR, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees),
    backLeftMotor(BACKLEFTMOTOR, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees),
    backRightMotor(BACKRIGHTMOTOR, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees) {
    drive = ChassisControllerBuilder()
        .withMotors({frontRightMotor, backRightMotor}, {frontLeftMotor, backLeftMotor})
        .withDimensions({AbstractMotor::gearset::green, 60/36}, {{15.5_in, 14_in}, imev5GreenTPR})
        .build();
    gearRatio = 1.667;
    diameterInches = 3;
    centerToWheelDistance = 5;
    };

int Chassis::distanceInTicks(float distance){
    //Green Gearbox takes 900 ticks for a rotation
    int distanceInTicks = (distance/(diameterInches*3.14159))*(900/gearRatio);
    //                    /* how many rotations */            /*motor clicks per rotation*/
    return distanceInTicks;
}

double Chassis::getLeftEncoder(){
    return (frontLeftMotor.getPosition() + backLeftMotor.getPosition()) / 2;
}

double Chassis::getRightEncoder(){
    return (frontRightMotor.getPosition() + backRightMotor.getPosition()) / 2;
}

void Chassis::move(float vertJoy, float horJoy){
    
    /*
    Calculate Velocity for right and left
    motors from the joystick values passed
    via vertjoy and horjoy
    */
    int leftSpeed = (vertJoy * 200) + (horJoy * 200);
    int rightSpeed = (vertJoy * 200) - (horJoy * 200);
    
    frontLeftMotor.moveVelocity(leftSpeed);
    backLeftMotor.moveVelocity(leftSpeed);
    frontRightMotor.moveVelocity(rightSpeed);
    backRightMotor.moveVelocity(rightSpeed);
}

void Chassis::driveInches(float distance, int speed){
    
    int moveTarget = distanceInTicks(distance);

    //drive forwards that amount
    frontLeftMotor.moveRelative(moveTarget, speed);
    backLeftMotor.moveRelative(moveTarget, speed);
    frontRightMotor.moveRelative(moveTarget, speed);
    backRightMotor.moveRelative(moveTarget, speed);
}

void Chassis::turn(int degrees, int speed){
    int moveTarget = distanceInTicks((2*3.14159*centerToWheelDistance)/(360/degrees));

    frontLeftMotor.moveRelative(moveTarget, -speed);
    backLeftMotor.moveRelative(moveTarget, -speed);
    backRightMotor.moveRelative(moveTarget, speed);
    frontRightMotor.moveRelative(moveTarget, speed);
}
