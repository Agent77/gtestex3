//
// Created by Tiki Lobel on 11/29/16.
//

#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include "Trip.h"
#include "Driver.h"
#include "Point.h"


class TaxiCenter {
private:
    Driver drivers[10];
    Point* locations;
    Trip trips[10];
public:
    TaxiCenter();
    Driver findDriver(Trip t);
    Trip createTrip(Passenger p);
    void setLocation(int index, Point location);
    void setTaxiLocations(Point p[]);
    void addTrip(Passenger p);
    void updateMeters();
    int checkDestinations();
    Point* getLocations() { return locations;}
    Trip* getTrips(){ return trips;};

};


#endif //EX2_TAXICENTER_H
