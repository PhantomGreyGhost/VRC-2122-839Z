#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "cautiontape/robotConfig.hpp"

using namespace okapi;

namespace cautionTape {
    class Chassis {
        public:
        okapi::Motor frontLeftMotor;
        okapi::Motor backLeftMotor;
        okapi::Motor frontRightMotor;
        okapi::Motor backRightMotor;

        Chassis();

        float gearRatio;
        float diameterInches;
        float centerToWheelDistance;

        std::shared_ptr<okapi::ChassisController> drive;
        int distanceInTicks(float distance);
        double getLeftEncoder();
        double getRightEncoder();
        void move(float vertJoy, float horJoy);
        void driveInches(float distance, int speed);
        void turn(int degrees, int speed);
    };
}
