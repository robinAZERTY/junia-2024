#pragma once

#include "element.hpp"


class Hole : public FixedElement {
    public:
        Hole(Environment *environment = nullptr, double x=0, double y=0);

        double get_depth() const;
        void set_depth(double depth);

        Element* get_element_inside() const;
        int set_element_inside(Element* element_inside);

        int update(double dt) override{return 0;}


    private:
        double depth_{0};
        Element* element_inside_{nullptr};
        static unsigned int id_counter;
};