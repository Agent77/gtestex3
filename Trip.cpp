
#include "Trip.h"

Trip::Trip() {

}

Trip::Trip(int tripId, int xStart, int yStart, int xEnd, int yEnd, int numOfPassengers, double tariff) {
    this->tripId=tripId;
    this->xStart=xStart;
    this->yStart=yStart;
    this->xEnd=xEnd;
    this->yEnd=yEnd;
    this->numOfPassengers=numOfPassengers;
    this->tariff=tariff;
}

Trip::~Trip() {

}

int Trip::getId() {
    return tripId;
}

int Trip::getMeters() {
    return metersPassed;
}

int Trip::getNumOfPassengers() {
    return numOfPassengers;
}

double Trip::getTariff() {
    return tariff;
}
Coordinate* Trip::getStart() {
    Coordinate* start = new Point(xStart, yStart);
    return start;
}
Coordinate* Trip::getEnd() {
    Coordinate* end = new Point(xEnd, yEnd);
    return end;
}

void Trip::addMeters() {
    metersPassed =+1;
}

void Trip::updateStartPoint(Coordinate *c){
    xStart= c->getNextCoordinate(0);
    yStart=c->getNextCoordinate(1);
}