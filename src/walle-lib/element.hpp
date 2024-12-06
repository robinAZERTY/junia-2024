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
        void set_position(Vector2<double> position) { position_ = position; }

        double get_orientation() const { return orientation_; }
        void set_orientation(double orientation) { orientation_ = orientation; }

        Environment *get_environment() const { return environment_; }
        void set_environment(Environment *environment) { environment_ = environment; }
    
    protected :
        Vector2<double> position_{0, 0};
        double orientation_{0};
        double collision_radius_{0};
        Environment *environment_{nullptr};
};

class FixedElement : public Element {
    public:
        FixedElement(Environment *environment = nullptr) : Element(environment) {}
        FixedElement(double x, double y, Environment *environment = nullptr) : Element(x, y, environment) {}
};

class MovableElement : public Element {
    public:
        MovableElement(Environment *environment = nullptr) : Element(environment) {}
        MovableElement(double x, double y, Environment *environment = nullptr) : Element(x, y, environment) {}

        double get_linear_speed() const { return linear_speed_; }
        void set_linear_speed(double linear_speed) { linear_speed_ = linear_speed; }

        double get_angular_speed() const { return angular_speed_; }
        void set_angular_speed(double angular_speed) { angular_speed_ = angular_speed; }
        

        void move_according_velocities(double dt) {
            orientation_ += angular_speed_ * dt;
            position_ += Vector2<double>{cos(orientation_), sin(orientation_)} * linear_speed_ * dt;
        }

    private:
        double linear_speed_{0};
        double angular_speed_{0};
};