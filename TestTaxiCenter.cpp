
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
    tc.addTrip(t1);
    //tc.addTrip(t2);
    Driver d1 = Driver(77,30,'M',2, 12);
    Driver d2 = Driver(28,45,'W',1, 45);
    tc.addDriver(d1);
    Taxi taxi = Taxi(12,'H','R');
    tc.addTaxi(taxi);
    //tc.addDriver(d2);
    tc.assignDrivers();
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
/*TEST_F(TestTaxiCenter, FindDriver) {
    Graph *grid = new Grid(5, 5);
    TaxiCenter tc = TaxiCenter(grid);
    Trip t1 = Trip(77,3,3,1,1,2,3);
    Trip t2 = Trip(10,2,2,3,4,1,7);
    Driver d1 = Driver(77,30,'M',2, 12, grid);
    Driver d2 = Driver(28,45,'W',1, 45, grid);
    tc.addDriver(d1);
    tc.addDriver(d2);
    tc.addTrip(t1);
    tc.addTrip(t2);
    //tc.assignDrivers();
    tc.driveAll();
    Trip newTrip = Trip(2,3,4,2,1, 1, 10);
    tc.addTrip(newTrip);
    tc.assignDrivers();
    Point* p = new Point(2,1);
    ASSERT_TRUE(d1.getTrip().getEnd()->equalTo(p)) << "Wrong assignment.";
    delete grid;
    delete p;
    }*/