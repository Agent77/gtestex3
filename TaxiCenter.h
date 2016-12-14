//
// Created by Tiki Lobel on 11/29/16.
//

#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include "Trip.h"
#include "Driver.h"
#include "Point.h"
#include <vector>

using namespace std;

class TaxiCenter {
private:
    std::vector<Driver> drivers;
    std::vector<Taxi> taxis;
    Point* locations;
    std::vector<Trip> trips;
    Graph* map;
public:
    TaxiCenter();
    TaxiCenter(Graph* map1);
    ~TaxiCenter() {};
    int assignDrivers();
    void driveAll();
    Driver findClosestDriver(Trip t);
    void addDriver(int driverId, int age, char mStatus, int vehicleId, int exp);
    void addTrip(Trip t);
    void updateMeters();
    int checkDestinations();
    void addTrip(int tripId, int xStart, int yStart, int xEnd, int yEnd,
                 int numPassengers, double tariff);
    void requestDriverLocation(int driverId);
    vector <Driver> getDrivers();
    vector<Trip> getTrips();
    void addTaxi(Taxi t);
    void addDriver(Driver d);
};


#endif //EX2_TAXICENTER_H
