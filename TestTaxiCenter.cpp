
#include "gtest/gtest.h"
#include "TestTaxiCenter.h"

/*
 * Tests that a a trip has been added to the taxiCenter.
 */
TEST_F(TestTaxiCenter, addTrip) {
    TaxiCenter tc = TaxiCenter();
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t2);
    int size = sizeof(tc.getTrips())/4;
    tc.addTrip(t1);
    int newSize = sizeof(tc.getTrips())/4;
    ASSERT_GT(newSize,size)<< "Did not add trip.";
}

TEST_F(TestTaxiCenter, AssignDrivers) {
    TaxiCenter tc = TaxiCenter();
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12, NULL);
    Driver d2 = Driver(28,45,'W',1, 45, NULL);
    tc.addDriver(d1);
    Taxi taxi = Taxi(23,'H','R');
    tc.addTaxi(taxi);
    //tc.addDriver(d2);
    tc.assignDrivers();
    vector<Driver> drivers = tc.getDrivers();
    vector<Trip> trips = tc.getTrips();
    ASSERT_EQ(drivers.at(0).getvehicleId(), trips.at(0).getId()) << "Wrong assingment of Trip.";
    ASSERT_EQ(drivers.at(0).getTaxi().getId(),23) << "Taxi assigned incorrectly.";

}

TEST_F(TestTaxiCenter, DriveAll) {
    TaxiCenter tc = TaxiCenter();
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12, NULL);
    Driver d2 = Driver(28,45,'W',1, 45, NULL);
    tc.addDriver(d1);
    Taxi taxi = Taxi(23,'H','R');
    tc.addTaxi(taxi);
    //tc.addDriver(d2);
    tc.assignDrivers();
    tc.driveAll();
    ASSERT_EQ(d1.getTrip().getStart()->getNextCoordinate(0), 1) << "Did not arrive at end.";

}

TEST_F(TestTaxiCenter, RequestDriverLoc) {
    TaxiCenter tc = TaxiCenter();
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12, NULL);
    Driver d2 = Driver(28,45,'W',1, 45, NULL);
    tc.addDriver(d1);
    tc.assignDrivers();
    string str = "(3,3)";
    testing::internal::CaptureStdout();
    tc.requestDriverLocation(77);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, str) << "Incorrect Format!";
    tc.driveAll();
    str = "(1,1)";
    testing::internal::CaptureStdout();
    tc.requestDriverLocation(77);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, str) << "Incorrect Format after drive!";
}
//c
/*
 * Tests that the closest available driver to a passenger is chosen.
 */
TEST_F(TestTaxiCenter, FindDriver) {//TODO FIX
    /*Passenger p= Passenger(Point(2,3), Point(3,3));
    TaxiCenter tc = TaxiCenter();
    Trip t = Trip(p.getSource().getX(),p.getSource().getY(),p.getDestination().getX(), p.getDestination().getY(),2,1,2);
    tc.setLocation(0,Point(2,1));
    tc.setLocation(1,Point(2,1)); //This is the right driver because its a luxury cab and will
    // arrive in one step
    tc.setLocation(2,Point(3,3));
    Driver rightDriver = Driver(123,25,"single");
    rightDriver.setTaxi(Taxi (123,10,"honda","green",500,100,true));
    Driver d = tc.findDriver(t);
    ASSERT_EQ(d.getId(),rightDriver.getId())<< "The findDriver method didn't find the right one";
*/}