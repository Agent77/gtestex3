
#ifndef EX2_TESTTRIP_H
#define EX2_TESTTRIP_H
#include "Trip.h"

/*
 * Test class for trip.
 */
class TestTrip: public::testing::Test {

public:
    void SetUp() {
        cout << "Setting Up.\n";
    }
    void TearDown() {
        cout<< "Tearing Down.\n";
    }
};


#endif //EX2_TESTTRIP_H
