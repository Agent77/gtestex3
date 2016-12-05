
#ifndef EX2_TESTTAXICENTER_H
#define EX2_TESTTAXICENTER_H
#include <gtest/gtest.h>
#include "TaxiCenter.h"

/*
 * Test class for taxiCenter.
 */
class TestTaxiCenter:public::testing::Test {
private:
    TaxiCenter tc;
public:
    void SetUp() {
        tc = TaxiCenter();
        tc.getLocations()[0] = Point(0,0);
        tc.getLocations()[1] = Point(1,1);
        tc.getLocations()[2] = Point(2,2);
        tc.getTrips()[0] = Trip(Point(3,3), Point(1,1));
        tc.getTrips()[1] = Trip(Point(2,2), Point(3,4));
    }
};


#endif //EX2_TESTTAXICENTER_H
