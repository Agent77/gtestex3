
#ifndef EX2_TESTTAXICENTER_H
#define EX2_TESTTAXICENTER_H
#include <gtest/gtest.h>
#include "TaxiCenter.h"
class TestTaxiCenter:public::testing::Test {
private:
    TaxiCenter tc;
public:
    /*void SetUp() {
        tc = TaxiCenter();
        tc.getLocations()[0] = Point(0,0);
        tc.getLocations()[1] = Point(1,1);
        tc.getLocations()[2] = Point(2,2);
        tc.getTrips()[0] = Trip(Point(3,3), Point(1,1));
        tc.getTrips()[1] = Trip(Point(2,2), Point(3,4));
    }*/ //todo segmentation fault


    void addTrip();
    void setLocation(Point* p);
    void setTaxiLocations();
    Driver findDriver(Trip t);
    Trip createTrip(Passenger p);
    void addTrip(Passenger p);
    void updateMeters();
    int checkDestinations();
};


#endif //EX2_TESTTAXICENTER_H
