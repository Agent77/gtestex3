
#include "gtest/gtest.h"
#include "TestTrip.h"

/*
 * Tests that a trip has updated its total meters member.
 */
TEST(TestTrip, AddMeters) {
    Trip t = Trip();
    int m = t.getMeters();
    t.addMeters();
    int m2 = t.getMeters();
    EXPECT_FALSE(m == m2) << "Didn't update meters!";
}