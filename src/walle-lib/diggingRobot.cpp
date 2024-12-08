#include "diggingRobot.hpp"

unsigned int DiggingRobot::id_counter = 0;

DiggingRobot::DiggingRobot(Environment* e, double mass, double size) : Robot(e, mass, size)
{
    id_counter++;
    label_ = "DiggingRobot" + std::to_string(id_counter);
}

void DiggingRobot::dig()
{
    if (battery_ < DiggingRobotProperties::DIGGING_POWER_CONSUMPTION)
        return;
    is_digging_ = true;
}

void DiggingRobot::stop_digging()
{
    is_digging_ = false;
}

int DiggingRobot::update(double dt)
{
    Robot::update(dt);
    if (is_digging_)
    {
        // is there already an hole? if not, create one
        auto hole = nearest<Hole>();
        if (!hole)
        {
            hole = new Hole(environment_, get_position_x(), get_position_y());
            hole->set_size(DiggingRobotProperties::DIGGING_SIZE);
            environment_->add_element(hole);
        }
        hole->set_depth(hole->get_depth() + DiggingRobotProperties::DIGGING_SPEED * dt);  // dig
    }
    return 0;
}

int DiggingRobot::update_battery(double dt)
{
    if (is_digging_)
        battery_ -= DiggingRobotProperties::DIGGING_POWER_CONSUMPTION * dt;
    return Robot::update_battery(dt);
}