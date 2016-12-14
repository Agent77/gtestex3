
#include "gtest/gtest.h"
#include "TestTrip.h"

/*
 * Tests that a trip has updated its total meters member.
 */
TEST_F(TestTrip, AddMeters) {
    Trip t = Trip();
    int m = t.getMeters();
    t.addMeters();
    int m2 = t.getMeters();
    EXPECT_FALSE(m == m2) << "Didn't update meters!";
}

TEST_F(TestTrip, UpdateStart) {
    Trip t = Trip(20,0,1,2,2,3,2);
    Point* point = new Point(0,1);
    t.updateStartPoint(point);
    ASSERT_TRUE(t.getStart()->equalTo(point)) << "Trip start not updated.";
}