#include "environnement.hpp"
#include <stdexcept>

Environment::Environment(double left, double right, double top, double bottom)
{
    // throw an exception if the values are not correct
    if (left > right && top > bottom)
        throw std::invalid_argument("left must be less than right and top must be less than bottom");
    if (left > right)
        throw std::invalid_argument("left must be less than right");
    if (top > bottom)
        throw std::invalid_argument("top must be less than bottom");

    left_ = left;
    right_ = right;
    top_ = top;
    bottom_ = bottom;
}

double Environment::left() { return left_; }
double Environment::right() { return right_; }
double Environment::top() { return top_; }
double Environment::bottom() { return bottom_; }