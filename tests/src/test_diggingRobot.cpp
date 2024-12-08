#include <gtest/gtest.h>
#include <walle-lib/diggingRobot.hpp>

TEST(DiggingRobot, test_constructor) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    EXPECT_EQ(r.get_mass(), 10);
    EXPECT_EQ(r.get_size(), 0.5);
    EXPECT_EQ(r.get_position().x(), 0);
    EXPECT_EQ(r.get_position().y(), 0);
    EXPECT_EQ(r.get_label(), "DiggingRobot1");
    EXPECT_EQ(r.get_battery_ratio(), 1);
}

TEST(DiggingRobot, test_digging) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    r.dig();
    r.update(1);
    auto h = e.get_elements<Hole>();
    EXPECT_EQ(h.size(), 1);
    EXPECT_EQ(h[0]->get_size(), DiggingRobotProperties::DIGGING_SIZE);
    EXPECT_EQ(h[0]->get_depth(), DiggingRobotProperties::DIGGING_SPEED);
    EXPECT_EQ(h[0]->get_position().x(), r.get_position().x());
    EXPECT_EQ(h[0]->get_position().y(), r.get_position().y());
}

TEST(DiggingRobot, test_filling) {
    Environment e;
    DiggingRobot r(&e, 10, 0.5);

    r.fill_soil();
    r.update(1);
    auto h = e.get_elements<Hole>();
    EXPECT_EQ(h.size(), 1);
    EXPECT_EQ(h[0]->get_size(), DiggingRobotProperties::DIGGING_SIZE);
    EXPECT_EQ(h[0]->get_depth(), -DiggingRobotProperties::FILLING_SPEED);
    EXPECT_EQ(h[0]->get_position().x(), r.get_position().x());
    EXPECT_EQ(h[0]->get_position().y(), r.get_position().y());
}