#include "environnement.hpp"
#include "element.hpp"
#include <stdexcept>

const char* InvalidBoundariesEnvironmentException::what() const noexcept
{
    return "Invalid environment boundaries, left must be less than right and top must be less than bottom";
}

Environment::Environment(double left, double right, double top, double bottom)
{
    // throw an exception if the values are not correct
    if (left > right || top > bottom)
        throw InvalidBoundariesEnvironmentException();

    left_ = left;
    right_ = right;
    top_ = top;
    bottom_ = bottom;
}

double Environment::left() const{ return left_; }
double Environment::right() const{ return right_; }
double Environment::top() const{ return top_; }
double Environment::bottom() const{ return bottom_; }

unsigned int Environment::get_elements() { return elements_.size(); }
void Environment::add_element(Element *element)
{
    elements_.push_back(element);
    element->set_environment(this);
}