
#include "robot.hpp"
#include <cmath>


void Robot::stop()
{
    set_linear_speed(0);
    set_angular_speed(0);
}

void Robot::run(double dt)
{
    move_according_velocities(dt);
}
