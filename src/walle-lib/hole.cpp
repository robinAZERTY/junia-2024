#include "hole.hpp"

Hole::Hole(Environment *environment) : FixedElement(environment) {}

Hole::Hole(double x, double y, Environment *environment) : FixedElement(x, y, environment) {}

double Hole::get_depth() const { return depth_; }

void Hole::set_depth(double depth) { depth_ = depth; }

Element* Hole::get_element_inside() const { return element_inside_; }

int Hole::set_element_inside(Element* element_inside) { 
    if (element_inside_ != nullptr)
        return -1; // already occupied
    if (element_inside->get_collision_radius() > get_collision_radius())
        return -2; // don't fit
    element_inside_ = element_inside;
    if (element_inside)
        element_inside->set_position(get_position());
    return 0;
}