
#include "robot.hpp"
#include <cmath>

double Robot::get_linear_speed() const
{
    return linear_speed_;
}

void Robot::set_linear_speed(double speed)
{
    linear_speed_ = speed;
}

void Robot::set_angular_speed(double vitesse_angulaire)
{
    angular_speed_ = vitesse_angulaire;
}

double Robot::get_angular_speed() const
{
return angular_speed_;
}

void Robot::stop()
{
    set_linear_speed(0);
    set_angular_speed(0);
}

void Robot::run(double dt)
{
    Vector2 vitesse = {cos(m_theta) * linear_speed_, sin(m_theta) * linear_speed_};
    position_ = position_ + vitesse * dt;
    m_theta += angular_speed_ * dt ;
}
