#include "diggingRobot.hpp"

unsigned int DiggingRobot::id_counter = 0;

DiggingRobot::DiggingRobot(Environment *e, double mass, double size) : Robot(e, mass, size)
{
    id_counter++;
    label_ = "DiggingRobot" + std::to_string(id_counter);
}

void DiggingRobot::dig()
{
    is_digging_ = true;
    stop_filling();
}

void DiggingRobot::stop_digging()
{
    is_digging_ = false;
}

void DiggingRobot::fill_soil()
{
    is_filling_ = true;
    stop_digging();
}

void DiggingRobot::stop_filling()
{
    is_filling_ = false;
}

int DiggingRobot::update(double dt)
{
    Robot::update(dt);
    if (is_digging_ || is_filling_)
    {
        // is there already an hole? if not, create one
        auto hole = nearest<Hole>();
        if (!hole)
        {
            hole = new Hole(environment_, get_position_x(), get_position_y());
            hole->set_size(DiggingRobotProperties::DIGGING_SIZE);
            environment_->add_element(hole);
        }
        double delta = 0;
        if (is_filling_)
            delta += DiggingRobotProperties::FILLING_SPEED; // fill
        if (is_digging_)
            delta -= DiggingRobotProperties::DIGGING_SPEED; // dig
        delta *= dt;
        hole->set_depth(hole->get_depth() + delta);
        soil_quantity_ -= delta;
        mass_ -= delta * DiggingRobotProperties::SOIL_DENSITY;
    }
    return 0;
}

int DiggingRobot::update_battery(double dt)
{
    if (is_digging_)
        battery_ -= DiggingRobotProperties::DIGGING_POWER_CONSUMPTION * dt;
    if (is_filling_)
        battery_ -= DiggingRobotProperties::FILLING_POWER_CONSUMPTION * dt;
    return Robot::update_battery(dt);
}