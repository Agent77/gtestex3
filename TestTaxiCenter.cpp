
#include "gtest/gtest.h"
#include "TestTaxiCenter.h"

/*TEST_F(TestTaxiCenter, addTrip) {
    TaxiCenter tc = TaxiCenter();
    tc.getLocations()[0] = Point(0,0);
    tc.getLocations()[1] = Point(1,1);
    tc.getLocations()[2] = Point(2,2);
    tc.getTrips()[0] = Trip(Point(3,3), Point(1,1));
    tc.getTrips()[1] = Trip(Point(2,2), Point(3,4));
    int size = sizeof(tc.getTrips())/4;
    tc.addTrip(Passenger());
    int newSize = sizeof(tc.getTrips())/4;
    ASSERT_GT(newSize,size)<< "Did not add trip.";
}*/ //todo segmentation fault

TEST_F(TestTaxiCenter, setTaxiLocations) {
    TaxiCenter tc = TaxiCenter();
    Point p[3];
    p[0] = Point(3,3);
    p[1] = Point(2,2);
    p[2] = Point(1,1);
    tc.setTaxiLocations(p);
    ASSERT_EQ(tc.getLocations()[0].getX(), p[0].getX()) << "Did not set new Location in place 0.";
    ASSERT_EQ(tc.getLocations()[1].getX(), p[1].getX()) << "Did not set new Location in place 1.";
    ASSERT_EQ(tc.getLocations()[2].getX(), p[2].getX()) << "Did not set new Location in place 2.";
}

/*TEST_F(TestTaxiCenter, checkDestinations) {
    TaxiCenter tc = TaxiCenter();
    tc.getLocations()[0] = Point(0,0);
    tc.getLocations()[1] = Point(1,1);
    tc.getLocations()[2] = Point(2,2);
    tc.getTrips()[0] = Trip(Point(3,3), Point(1,1));
    tc.getTrips()[1] = Trip(Point(2,2), Point(3,4));
    tc.setLocation(0, Point(3,3));
    tc.setLocation(1, Point(2,2));
    int index = tc.checkDestinations();
    //Should be -1 because did not arrive at any destination
    ASSERT_EQ(index, -1) << "Incorrect return value.";
    tc.setLocation(0, Point(1,1));
    index = tc.checkDestinations();
    //Should find a destination match at index 0 of locations
    ASSERT_EQ(index, 0) << "Doesnt know that it arrived at destination 0.";
}*/ //todo segmentation fault
TEST_F(TestTaxiCenter, FindDriver) { //TODO

//Take into account luxury vs standard cabs arriving faster
}
/*TEST_F(TestTaxiCenter, CreateTrip) { //TODO
//Make sure takes information from passenger correctly
    TaxiCenter tc = TaxiCenter();
    Passenger pass = Passenger (Point (1,2),Point (3,3));
    tc.createTrip(pass);
    Trip tr= (Point (1,2), Point(3,3)); //todo error
    ASSERT_EQ(pass.getSource(),tr.getSource())<<"TaxiCenter didn't get passanger's source";
    ASSERT_EQ(pass.getDestination(),tr.getDest())<<"TaxiCenter didn't get passanger's destination";
}*/
/*TEST_F(TestTaxiCenter, SetTaxiLocations) {//TODO
 //Checks that locations are all updated
    TaxiCenter tc = TaxiCenter();
    Point p[3];
    p[0]=Point (1,2);
    p[1]=Point(2,3);
    p[2]=Point(0,3);
    tc.setLocation(p); //todo error
    ASSERT_EQ(tc.getLocations()[0],p[0])<<"first driver's location hasn't been updated";
    ASSERT_EQ(tc.getLocations()[1],p[1])<<"second driver's location hasn't been updated";
    ASSERT_EQ(tc.getLocations()[2],p[2])<<"third driver's location hasn't been updated";
}*/

//Comment