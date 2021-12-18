#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "cautiontape/robotConfig.hpp"

using namespace okapi;

namespace cautionTape {
    class Claw {
        public:
        pros::ADIDigitalOut claw;

        Claw();

        bool closed;

        void close();
        void open();
    };
}
