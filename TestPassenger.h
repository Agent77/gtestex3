
#ifndef EX2_TESTPASSENGER_H
#define EX2_TESTPASSENGER_H
#include "Point.h"
#include "Passenger.h"
#include <gtest/gtest.h>

/*
 * Test class for passenger.
 */
class TestPassenger:public::testing::Test {
protected:
    Passenger p;
public:
    void SetUp() {
        cout << "Setting Up.\n";
        p = Passenger(Point(1,2),Point(3,4));
    }
    void TearDown() {
        cout<< "Tearing Down.\n";
    }
};


#endif //EX2_TESTPASSENGER_H
