#pragma once 

#include "environnement.hpp"
#include "element.hpp"

/// Generic robot class inheriting from MovableElement (can move in the environment).
class Robot : public MovableElement
{
public:
    Robot(Environment* e=nullptr) : MovableElement(e) {}

    /// Stops the robot.
    void stop();

    /// update the robot's position and orientation according to its linear and angular speeds.
    void run(double dt);

};


