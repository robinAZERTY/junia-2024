#pragma once

#include <vector>

#include "element.hpp"
#include "robot.hpp"

namespace ChargingStationProperties {
    constexpr double REFUEL_RATE = 100; // W
    constexpr double MIN_DISTANCE_TO_CHARGE = 0.5; // m
}

class ChargingStation : public FixedElement {
    public:
        ChargingStation(Environment *environment = nullptr, double x=0, double y=0) : FixedElement(environment, x, y) {}

        int attach(Robot* robot);
        void detach(Robot* robot);
        bool isNear(Robot* robot) const;
        void run(const double dt);

    private:
        std::vector<Robot*> robotsInCharge_;
};