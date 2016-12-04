#ifndef EX2_TRIP_H
#define EX2_TRIP_H

#include "Point.h"
class Trip {

private:

    int rideID;
    int metersPassed;
    int numOfPassengers;
    int tariff;
    Point source;
    Point destination;

public:
    Trip();
    Trip(Point s, Point d);
    ~Trip();
    int getId();
    int getMeters();
    int getNumOfPassengers();
    int getTariff();
    Point getSource();
    Point getDest();
    void addMeters(){};

};


#endif //EX2_TRIP_H
