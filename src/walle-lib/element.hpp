#pragma once

class Environment;

class Element {
    public:
        friend class Environment;

        Element(Environment *environment = nullptr) : environment_(environment) {}

        double get_position_x() const { return x_; }
        double get_position_y() const { return y_; }
        Environment *get_environment() const { return environment_; }
    protected :
        double x_, y_, collision_radius_;
        Environment *environment_ = nullptr;
};