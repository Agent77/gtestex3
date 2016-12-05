
#include "TestCity.h"

/*
 * Test for checking for passenger input, by
 * checking if a passenger was added
 * to the TaxiCenter
 */
TEST_F(TestCity, PassengerCalls) {
    int count = 0;
    Passenger p = Passenger();
    TaxiCenter tc = c.getTaxiCenter();
    Trip* t =  tc.getTrips();
    for(int i = 0; i < sizeof(t)/4; i++) {
        count += t[i].getNumOfPassengers();
    }
    int count1 = count;
    c.CallTaxiCenter(p);
    for(int i = 0; i < sizeof(t)/4; i++) {
        count += t[i].getNumOfPassengers();
    }
    int count2 = count;
    //Should be +1
    EXPECT_FALSE(count1 == count2) << "Didn't add new passenger.";
}