#pragma once
#include "vector2.hpp"

class Environment;

class Element {
    public:

        Element(Environment *environment = nullptr) : environment_(environment) {}
        Element(double x, double y, Environment *environment = nullptr) : position_(x,y), environment_(environment) {}

        double get_position_x() const { return position_.x(); }
        double get_position_y() const { return position_.y(); }
        Vector2<double> get_position() const { return position_; }
        void set_position(double x, double y) { position_ = {x, y}; }

        Environment *get_environment() const { return environment_; }
        void set_environment(Environment *environment) { environment_ = environment; }
    
    protected :
        Vector2<double> position_{0, 0};
        double collision_radius_{0};
        Environment *environment_{nullptr};
};
