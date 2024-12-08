#pragma once

#include "robot.hpp"
#include "hole.hpp"

namespace DiggingRobotProperties
{
    constexpr double DIGGING_POWER_CONSUMPTION = 100; // W
    constexpr double DIGGING_SPEED = 0.1;             // m/s
    constexpr double DIGGING_SIZE = 0.3;              // m
}

class DiggingRobot : public Robot
{
public:
    DiggingRobot(Environment *e = nullptr, double mass = 10, double size = 0.5);

    void dig();
    void stop_digging();
    int update(double dt) override;

protected:
    static unsigned int id_counter;
    int update_battery(double dt) override;
    bool is_digging_ = false;
};