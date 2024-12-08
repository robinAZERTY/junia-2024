#include "hole.hpp"

unsigned int Hole::id_counter = 0;

Hole::Hole(Environment *environment, double x, double y) : FixedElement(environment, x, y)
{
    id_counter++;
    label_ = "Hole" + std::to_string(id_counter);
}

double Hole::get_depth() const { return depth_; }

void Hole::set_depth(double depth) { depth_ = depth; }

Tree *Hole::get_tree_inside() const { return tree_inside_; }

int Hole::set_tree_inside(Tree *tree_inside)
{
    if (tree_inside != nullptr)
    {
        if (tree_inside_ != nullptr)
            return -1; // already occupied 
        if (tree_inside->get_collision_radius()/2 > get_size())
            return -2; // don't fit
        
        tree_inside->set_position(get_position());
    }

    tree_inside_ = tree_inside;
    return 0;
}