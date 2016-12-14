#include "Driver.h"

Driver::Driver() {

}

Driver::Driver(int driverId, int age, char mStatus, int exp, int vehicleId, Graph* map) {
    numberOfcustomers=0;
    this->driverId=driverId;
    this->age=age;
    this->maritalStatus=mStatus;
    this->vehicleId=vehicleId;
    this->exp=exp;
    this->gps = map;
}

Driver::Driver(int driverId, int age, char mStatus, int exp, int vehicleId) {
    numberOfcustomers=0;
    this->driverId=driverId;
    this->age=age;
    this->maritalStatus=mStatus;
    this->vehicleId=vehicleId;
    this->exp=exp;
}

void Driver::drive() {
    BFS bfs = BFS(gps);
    Coordinate *c;
    do {
        if(myTrip.getStart()->equalTo(myTrip.getEnd())) {
            break;
        }
        c  = bfs.getNextInPath(myTrip.getStart(), myTrip.getEnd());
        myTrip.updateStartPoint(c);
    } while(myTrip.getStart() != myTrip.getEnd());
}


int Driver::getAge() {
    return age;
}

int Driver::getDriverId() {
    return driverId;
}

double Driver::getSatisfaction() {
    return avgSatisfaction;
}

Taxi Driver::getTaxi() {
    return taxi;
}

Trip Driver::getTrip() {
    return myTrip;
}

vector<Passenger> Driver::getPassengers() {
    return myPassengers;
}

char Driver::getMaritalStatus() {
    return maritalStatus;
}

void Driver::setTaxi(Taxi t) {
    taxi =t;
}

void Driver::setTrip(Trip t) {
    myTrip=t;
}

void Driver::rateMe(int rating) {
    numberOfcustomers=+1;
    totalRate+=rating;
    avgSatisfaction =totalRate/numberOfcustomers;
}

void Driver::addPassenger(Passenger p) {
    myPassengers.push_back(p);
}

Driver::~Driver() {

}