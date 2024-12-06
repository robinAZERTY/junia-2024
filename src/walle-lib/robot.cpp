
#include "robot.hpp"
#include <cmath>


void Robot::stop()
{
    set_linear_speed(0);
    set_angular_speed(0);
}

int Robot::run(double dt)
{
    auto battery_status = update_battery(dt);
    move_according_velocities(dt);
    
    if (battery_status == Robot::BATTERY_STATUS::EMPTY)
        return Robot::STATUS::EMPTY_BATTERY;
    if (battery_status == Robot::BATTERY_STATUS::LOW)
        return Robot::STATUS::LOW_BATTERY;
    
    return 0;
}

int Robot::update_battery(double dt)
{
    battery_ -= RobotEnergyProperties::MINIMUM_POWER_CONSUMPTION * dt;
    battery_ -= RobotEnergyProperties::MOVING_POWER_CONSUMPTION * get_linear_speed() * get_mass() * dt;

    if (battery_ <= 0)
    {
        stop();
        return Robot::BATTERY_STATUS::EMPTY;
    }
    if (battery_ < RobotEnergyProperties::LOW_BATTERY_THRESHOLD * battery_capacity_)
        return Robot::BATTERY_STATUS::LOW;

    return Robot::BATTERY_STATUS::OK;
}
