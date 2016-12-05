
#include "TestDriver.h"
#include "gtest/gtest.h"

/*
 * Tests the rate function, ensuring the number
 * is the average of given ratings
 */
TEST_F(TestDriver, RateDriver) {
    d.rateMe(4);
    EXPECT_TRUE(d.getSatisfaction() == 4) << "Satisfcation incorrect.";
    d.rateMe(3);
    ASSERT_TRUE(d.getSatisfaction() == 3.5) << "WRONG AVERAGE";
}

/*
 * Tests the add Passenger function of Driver, by
 * checking if their number of passengers increased
 */
TEST_F(TestDriver, AddPassenger) {
    int p1 = sizeof(d.getPassengers())/4;
    Passenger passenger = Passenger();
    d.addPassenger(passenger);
    int p2 = sizeof(d.getPassengers())/4;
    ASSERT_GE(p2, p1) << "Did not add Passenger. ";
}