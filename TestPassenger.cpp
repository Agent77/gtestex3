
#include "gtest/gtest.h"
#include "TestPassenger.h"

/*
 * Tests that the passenger's constructor initialized its members as expected.
 */
TEST_F(TestPassenger, PassengerConstructor) {
    //Passenger p = Passenger(Point(1,2),Point(3,4));
    int x = p.getSource().getX();
    int y = p.getSource().getY();
    ASSERT_EQ(x, 1) << "sourceX not set correctly.";
    ASSERT_EQ(y, 2) << "sourceY not set correctly.";
    x = p.getDestination().getX();
    y = p.getDestination().getY();
    ASSERT_EQ(x, 3) << "destX not set correctly.";
    ASSERT_EQ(y, 4) << "destY not set correctly.";
}

/*
 * Tests that the passenger's rate is between 1 to 5.
 */
TEST_F(TestPassenger, RateDriver) {
    int rating = p.rateDriver();
    ASSERT_GE(rating,1) << "Rating is less 1.";
    ASSERT_LE(rating, 5) << "Rating is greater than 5.";
}

/*
 * Tests the source and destination values of a passenger.
 */
TEST_F(TestPassenger, Source) {
    Point source = p.getSource();
    Point dest = p.getDestination();
    ASSERT_EQ(source.getX(), 1) << "Wrong source X.";
    ASSERT_EQ(source.getY(), 2) << "Wrong source Y.";
    ASSERT_EQ(dest.getX(), 3) << "Wrong dest X.";
    ASSERT_EQ(dest.getY(), 4) << "Wrong dest Y.";
}
