#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "cautiontape/robotConfig.hpp"

using namespace okapi;

namespace cautionTape {
    class Arm {
        public:
        okapi::Motor leftArmMotor;
        okapi::Motor rightArmMotor;

        Arm();

        std::shared_ptr<okapi::AsyncPosPIDController> armMove;
        void up();
        void down();
        void stop();
        void moveLocation();
    };
}
