#pragma once

#include "element.hpp"

namespace TreeProperties {
    constexpr double MAX_GROWTH_RATE = 0.1;
    constexpr double MAX_HEIGHT = 10;
    constexpr double MAX_SIZE = 0.6;
    constexpr double MIN_NUTRIENTS = 0.1;
    constexpr double MIN_SIZE = 0.06;
    constexpr double MIN_HEIGHT = 0.3;
}

class Tree : public FixedElement {
    public:
        Tree(Environment *environment = nullptr) ;
        Tree(double x, double y, Environment *environment = nullptr) ;

        void plant();

        void feed(double nutrients);

        double grow(double dt);

        double get_height() const;

    private:
        double height_{TreeProperties::MIN_HEIGHT};
        double soil_nutrients_{0};
        bool planted_{false};
};