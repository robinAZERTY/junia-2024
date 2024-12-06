#include "chargingStation.hpp"
#include <algorithm>

int ChargingStation::attach(Robot* robot) {
    if (!isNear(robot)) {
        return -1;
    }
    robotsInCharge_.push_back(robot);
    return 0;
}

bool ChargingStation::isNear(Robot* robot) const {
    const double distance = (robot->get_position() - get_position()).norm2();
    return distance + robot->get_collision_radius() + collision_radius_ <= ChargingStationProperties::MIN_DISTANCE_TO_CHARGE;
}

void ChargingStation::detach(Robot* robot) {
    robotsInCharge_.erase(std::remove(robotsInCharge_.begin(), robotsInCharge_.end(), robot), robotsInCharge_.end());
}

void ChargingStation::run(const double dt) {
    for (Robot* robot : robotsInCharge_) {
        robot->set_battery(robot->get_battery() + ChargingStationProperties::REFUEL_RATE * dt);
        if (robot->get_battery_ratio() >= 1 || !isNear(robot)) {
            detach(robot);
        }
    }
}