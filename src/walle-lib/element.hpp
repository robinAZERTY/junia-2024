#pragma once
// #include "environnement.hpp"
class Environment;

class Element {
    public:
        Element(){};

        double get_position_x() const { return x_; }
        double get_position_y() const { return y_; }
        Environment *environment_ = nullptr;
    protected :
        double x_, y_, collision_radius_;
};
