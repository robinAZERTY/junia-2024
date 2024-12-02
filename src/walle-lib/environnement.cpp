#include "environnement.hpp"

Environment::Environment(double left, double right, double top, double bottom)
{
    left_ = left;
    right_ = right;
    top_ = top;
    bottom_ = bottom;
}

double Environment::left() { return left_; }
double Environment::right() { return right_; }
double Environment::top() { return top_; }
double Environment::bottom() { return bottom_; }