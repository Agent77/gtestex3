
#include "gtest/gtest.h"
#include "TestTaxiCenter.h"

/*
 * Tests that a a trip has been added to the taxiCenter.
 */
TEST_F(TestTaxiCenter, addTrip) {
    TaxiCenter tc = TaxiCenter();
    Point points[3];
    points[0] = Point(0,0);
    points[1] = Point(1,1);
    points[2] = Point(2,2);
    tc.setTaxiLocations(points);
    Trip* trips = tc.getTrips();
    trips[0] = Trip(Point(3,3), Point(1,1));
    trips[1] = Trip(Point(2,2), Point(3,4));
    int size = sizeof(trips)/4;
    tc.addTrip(Passenger());
    trips = tc.getTrips();
    int newSize = sizeof(trips)/4;
    ASSERT_GT(newSize,size)<< "Did not add trip.";
}

/*
 * Tests whether one of the cabs on the grid is in its destination at a given time.
 */
TEST_F(TestTaxiCenter, checkDestinations) {
    TaxiCenter tc = TaxiCenter();
    Point* locs = tc.getLocations();
    locs[0] = Point(0,0);
    locs[1] = Point(1,1);
    locs[2] = Point(2,2);
    Trip* trips = tc.getTrips();
    trips[0] = Trip(Point(3,3), Point(1,1));
    trips[1] = Trip(Point(2,2), Point(3,4));
    tc.setLocation(0, Point(3,3));
    tc.setLocation(1, Point(2,2));
    int index = tc.checkDestinations();
    //Should be -1 because did not arrive at any destination
    ASSERT_EQ(index, -1) << "Incorrect return value.";
    tc.setLocation(0, Point(1,1));
    index = tc.checkDestinations();
    //Should find a destination match at index 0 of locations
    ASSERT_EQ(index, 0) << "Doesnt know that it arrived at destination 0.";
}

/*
 * Tests that the closest available driver to a passenger is chosen.
 */
TEST_F(TestTaxiCenter, FindDriver) {
    Passenger p= Passenger(Point(2,3), Point(3,3));
    TaxiCenter tc = TaxiCenter();
    Trip t = Trip(p.getSource(),p.getDestination());
    tc.setLocation(0,Point(2,1));
    tc.setLocation(1,Point(2,1)); //This is the right driver because its a luxury cab and will
                                  // arrive in one step
    tc.setLocation(2,Point(3,3));
    Driver rightDriver = Driver(123,25,"single");
    rightDriver.setTaxi(Taxi (123,10,"honda","green",500,100,true));
    Driver d = tc.findDriver(t);
    ASSERT_EQ(d.getId(),rightDriver.getId())<< "The findDriver method didn't find the right one";
}

/*
 * Tests that a trip has been created with the correct information.
 */
TEST_F(TestTaxiCenter, CreateTrip) {
//Make sure takes information from passenger correctly
    TaxiCenter tc = TaxiCenter();
    Passenger pass = Passenger (Point (1,2),Point (3,3));
    tc.createTrip(pass);
    Trip tr = Trip(Point (1,2), Point(3,3));
    Point* trptrSource = new Point(tr.getSource().getX(), tr.getSource().getY());
    Point* trptrDest = new Point(tr.getDest().getX(), tr.getDest().getY());
    Point* ptrSource = new Point(pass.getSource().getX(), pass.getSource().getY());
    Point* ptrDest = new Point(pass.getDestination().getX(), pass.getDestination().getY());
    ASSERT_TRUE(ptrSource->equalTo(trptrSource)) << "TaxiCenter didn't get passanger's source";
    ASSERT_TRUE(ptrDest->equalTo(trptrDest)) << "TaxiCenter didn't get passanger's destination";
    delete trptrSource;
    delete  trptrDest;
    delete ptrDest;
    delete ptrSource;
}

/*
 * Tests that the new locations of the drivers on the grid has been updated.
 */
TEST_F(TestTaxiCenter, SetTaxiLocations) {
 //Checks that locations are all updated
    TaxiCenter tc = TaxiCenter();
    Point p[3];
    p[0]=Point (1,2);
    p[1]=Point(2,3);
    p[2]=Point(0,3);
    tc.setTaxiLocations(p);
    Point* locs;
    locs = tc.getLocations();
    ASSERT_TRUE(locs[0].getX() == p[0].getX() && p[0].getY() == locs[0].getY()) << "first driver's location hasn't been updated";
    ASSERT_TRUE(locs[1].getX() == p[1].getX() && p[1].getY() == locs[1].getY()) << "second driver's location hasn't been updated";
    ASSERT_TRUE(locs[2].getX() == p[2].getX() && p[2].getY() == locs[2].getY()) << "third driver's location hasn't been updated";
}