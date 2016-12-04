#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H

#include "Trip.h"
#include "Passenger.h"
#include "Taxi.h"
class Driver {
private:
    int driverID;
    int age;
    double avgSatisfaction;
    string maritalStatus;
    Taxi taxi;
    Trip myTrip;
    Passenger myPassengers[10];
public:
    Driver();
    ~Driver();
    Driver(int id, int age, string mStatus);
    int getAge();
    int getId();
    int getSatisfaction();
    Taxi getTaxi();
    Trip getTrip();
    Passenger* getPassengers();
    string getMaritalStatus();
    void setTaxi(Taxi t);
    void setTrip(Trip t);
    void rateMe(int rating);
    void addPassenger(Passenger p);




};


#endif //EX2_DRIVER_H
