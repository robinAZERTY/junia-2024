#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "element.hpp"

class Environment
{
public:
    Environment(double left=-1, double right=-1,
                double top=-1, double bottom=-1);

    double left();
    double right();
    double top();
    double bottom();

    unsigned int get_elements();
    void add_element(Element* element);

private:
    double left_;
    double right_;
    double top_;
    double bottom_;
    std::vector<Element*> elements_;
};
