#pragma once 
#include <cmath>
#include <string>

class Environment
{
public:
    Environment(double left=-1, double right=-1,
                double top=-1, double bottom=1);

    double left();
    double right();
    double top();
    double bottom();

private:
    double left_;
    double right_;
    double top_;
    double bottom_;
};
