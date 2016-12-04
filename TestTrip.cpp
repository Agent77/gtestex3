
#include "gtest/gtest.h"
#include "TestTrip.h"
TEST(TestTrip, AddMeters) {
    Trip t = Trip();
    int m = t.getMeters();
    t.addMeters(); //todo error undefined reference
    int m2 = t.getMeters();
    EXPECT_FALSE(m == m2) << "Didn't update meters!";
}