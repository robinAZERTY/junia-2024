#include <gtest/gtest.h>
#include <walle-lib/element.hpp>
#include <cmath>

TEST(Element, test_constructor) {

    Element e; // Creates an element with default values
    EXPECT_EQ(e.get_environment(), nullptr); // The element is not in an environment

    Element e2(0.1, -1.3); // Creates an element with specific position
    EXPECT_NEAR(e2.get_position_x(), 0.1, 0.00001); // The initial x position is 0.1
    EXPECT_NEAR(e2.get_position_y(), -1.3, 0.00001); // The initial y position is -1.3
}

TEST(Element, test_set_position) {

    Element e;
    for (int i = 0; i < 10; i++) {
        double x = (double)rand() / RAND_MAX * 100 - 50;
        double y = (double)rand() / RAND_MAX * 100 - 50;
        e.set_position(x, y);
        EXPECT_NEAR(e.get_position_x(), x, 0.00001);
        EXPECT_NEAR(e.get_position_y(), y, 0.00001);
    }
}

TEST(Element, test_set_orientation) {

    Element e;
    for (int i = 0; i < 10; i++) {
        double orientation = (double)rand() / RAND_MAX * 6.28318530718 - 3.14159265359;
        e.set_orientation(orientation);
        EXPECT_NEAR(e.get_orientation(), orientation, 0.00001);
    }
}


TEST(MovableElement, test_constructor) {

    MovableElement e; // Creates a movable element with default values
    EXPECT_EQ(e.get_environment(), nullptr); // The element is not in an environment
    EXPECT_NEAR(e.get_linear_speed(), 0, 0.00001); // The initial linear speed is 0
    EXPECT_NEAR(e.get_angular_speed(), 0, 0.00001); // The initial angular speed is 0
    EXPECT_NEAR(e.get_mass(), 0, 0.00001); // The initial mass is 1

    MovableElement e2(0.1, -1.3); // Creates a movable element with specific position
    EXPECT_NEAR(e2.get_position_x(), 0.1, 0.00001); // The initial x position is 0.1
    EXPECT_NEAR(e2.get_position_y(), -1.3, 0.00001); // The initial y position is -1.3
}



TEST(MovableElement, test_set_linear_speed) {

    MovableElement e;
    for (int i = 0; i < 10; i++) {
        double linear_speed = (double)rand() / RAND_MAX * 100 - 50;
        e.set_linear_speed(linear_speed);
        EXPECT_NEAR(e.get_linear_speed(), linear_speed, 0.00001);
    }
}

TEST(MovableElement, test_set_angular_speed) {

    MovableElement e;
    for (int i = 0; i < 10; i++) {
        double angular_speed = (double)rand() / RAND_MAX * 100 - 50;
        e.set_angular_speed(angular_speed);
        EXPECT_NEAR(e.get_angular_speed(), angular_speed, 0.00001);
    }
}

TEST(MovableElement, test_set_mass) {

    MovableElement e;
    for (int i = 0; i < 10; i++) {
        double mass = (double)rand() / RAND_MAX * 100 - 50;
        e.set_mass(mass);
        EXPECT_NEAR(e.get_mass(), mass, 0.00001);
    }
}

TEST(MovableElement, test_move_according_velocities)
{
    MovableElement e;
    e.set_position(0, 0);
    e.set_linear_speed(1);
    e.set_angular_speed(0.5);
    e.move_according_velocities(1);
    EXPECT_NEAR(e.get_position_x(), 1, 0.00001);
    EXPECT_NEAR(e.get_position_y(), 0, 0.00001);
    EXPECT_NEAR(e.get_orientation(), 0.5, 0.00001);

    e.set_position(0, 0);
    e.set_orientation(0);
    e.set_linear_speed(1);
    e.set_angular_speed(0.5);
    e.move_according_velocities(2);
    EXPECT_NEAR(e.get_position_x(), 2, 0.00001);
    EXPECT_NEAR(e.get_position_y(), 0, 0.00001);
    EXPECT_NEAR(e.get_orientation(), 1, 0.00001);

    e.set_position(0, 0);
    e.set_orientation(3.14159265359);
    e.set_linear_speed(1);
    e.set_angular_speed(0.5);
    e.move_according_velocities(1);
    EXPECT_NEAR(e.get_position_x(), -1, 0.00001);
    EXPECT_NEAR(e.get_position_y(), 0, 0.00001);
    EXPECT_NEAR(e.get_orientation(), 3.64159265359, 0.00001);
}