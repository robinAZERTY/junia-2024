#pragma once

class Element {
    public:
        Element() = default;
        virtual ~Element() = default;

        double get_position_x() const { return x_; }
        double get_position_y() const { return y_; }
    protected :
        double x_, y_, collision_radius_;
};
