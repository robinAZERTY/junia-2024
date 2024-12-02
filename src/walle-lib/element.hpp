#pragma once

class Environment;

class Element {
    public:
        friend class Environment; // Environment needs to access the protected members of Element

        Element(Environment *environment = nullptr) : environment_(environment) {}
        Element(double x, double y, Environment *environment = nullptr) : x_(x), y_(y), environment_(environment) {}

        double get_position_x() const { return x_; }
        double get_position_y() const { return y_; }
        Environment *get_environment() const { return environment_; }
    
    protected :
        double x_{0}, y_{0}, collision_radius_{0};
        Environment *environment_{nullptr};
};
