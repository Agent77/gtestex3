
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
    int size = (int)tc.getTrips().size();
    tc.addTrip(t1);
    int newSize = (int)tc.getTrips().size();
    ASSERT_GT(newSize,size)<< "Did not add trip.";
}

TEST_F(TestTaxiCenter, AssignDrivers) {
    TaxiCenter tc = TaxiCenter();
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1); //TODO didnt add trip
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12);
    Driver d2 = Driver(28,45,'W',1, 45);
    tc.addDriver(d1);
    Taxi taxi = Taxi(12,'H','R');
    tc.addTaxi(taxi);
    //tc.addDriver(d2);
    tc.assignDrivers(); //TODO didnt enter right vehicle id
    vector<Driver> drivers = tc.getDrivers();
    ASSERT_EQ(drivers.at(0).getTrip().getStart()->getX(), 3) << "Wrong assingment of Trip.";
    ASSERT_EQ(drivers.at(0).getTaxi().getId(),12) << "Taxi assigned incorrectly.";

}

TEST_F(TestTaxiCenter, DriveAll) {
    Graph *grid = new Grid(5, 5);
    TaxiCenter tc = TaxiCenter(grid);
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12, grid);
    Driver d2 = Driver(28,45,'W',1, 45, grid);
    tc.addDriver(d1);
    Taxi taxi = Taxi(23,'H','R');
    tc.addTaxi(taxi);
    //tc.addDriver(d2);
    tc.driveAll();
    vector<Driver> drs2 = tc.getDrivers();
    ASSERT_EQ(drs2.at(0).getTrip().getStart()->getNextCoordinate(0), 1) << "Did not arrive at end.";
    delete grid;
}

TEST_F(TestTaxiCenter, RequestDriverLoc) {
    Graph *grid = new Grid(5, 5);
    TaxiCenter tc = TaxiCenter(grid);
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12, grid);
    Driver d2 = Driver(28,45,'W',1, 45, grid);
    tc.addDriver(d1);
    tc.assignDrivers();
    string str = "(3,3)";
    testing::internal::CaptureStdout();
    tc.requestDriverLocation(77);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, str) << "Incorrect Format!";
    delete grid;
    grid = new Grid(5, 5);
    TaxiCenter tc2 =  TaxiCenter(grid);
    t1 = Trip(77,3,3,1,1,2,3);
    tc2.addTrip(t1);
    d1 = Driver(77,30,'M',2, 12, grid);
    tc2.addDriver(d1);
    tc2.driveAll();
    str = "(1,1)";
    testing::internal::CaptureStdout();
    tc2.requestDriverLocation(77);
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