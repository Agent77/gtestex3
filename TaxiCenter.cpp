
#include "TaxiCenter.h"
#include "Driver.h"
using namespace std;
TaxiCenter::TaxiCenter() {

}

TaxiCenter::TaxiCenter(Graph* map1) {
    map = map1;
}
//Checks BFS to find the closest driver to passenger source
Driver TaxiCenter::findClosestDriver(Trip t) {

}

void TaxiCenter::addDriver(Driver d) {
    addDriver(d.getDriverId(), d.getAge(), d.getMaritalStatus(), d.getExp(), d.getvehicleId());
            //driverId, int age, char mStatus, int vehicleId, int exp
}



void TaxiCenter::updateMeters() {

}

int TaxiCenter::checkDestinations()  {
}




void TaxiCenter::requestDriverLocation(int driverId){
    vector<Driver>::iterator iter = drivers.begin();
    while((*(iter)).getDriverId() != driverId) {
        iter++;
    }
    cout<<*(*(iter)).getTrip().getStart()<<endl;
}

int TaxiCenter::assignDrivers() {
    int count = 0;

    //Assign taxi to driver according to....
    vector<Taxi>::iterator taxi = taxis.begin();
    vector<Driver>::iterator driver = drivers.begin();

    while(taxi != taxis.end()) {
        Taxi currentTaxi = *taxi;
        while((*(driver)).getvehicleId() != (currentTaxi).getId()) {
            driver++;
        }
        Driver* driverMatch = &(*(driver));
        driverMatch->setTaxi(*taxi);
        taxi++;
    }
    taxis.clear();

    vector<Driver>::iterator driverList = drivers.begin();
    vector<Trip>::iterator trip = trips.begin();
    while(driverList != drivers.end() && trip != trips.end()) {
        (*(driverList)).setTrip((*(trip)));
        driverList++;
        trip++;
        count++;
    }
    trips.clear();
    return count;
}

vector <Driver> TaxiCenter::getDrivers (){
    return drivers;
}

void TaxiCenter::driveAll() {
    assignDrivers();
    vector<Driver>::iterator currentDriver = drivers.begin();
    while(currentDriver != drivers.end()) {
        (*(currentDriver)).drive();
        currentDriver++;
    }
}

void TaxiCenter::addTaxi(Taxi t) {
    taxis.push_back(t);
}

vector<Trip> TaxiCenter::getTrips() {
    return trips;
}


void TaxiCenter::addTrip(Trip t) {
    trips.push_back(t);
}

void TaxiCenter::addTrip(int tripId, int xStart, int yStart, int xEnd, int yEnd,
                         int numPassengers, double tariff) {
    Trip* trip = new Trip (tripId, xStart, yStart,xEnd,yEnd,numPassengers,tariff);
    trips.push_back(*trip);
}

void TaxiCenter::addDriver(int driverId, int age, char mStatus, int vehicleId, int exp) {
    Driver* driver = new Driver (driverId, age, mStatus, vehicleId, exp, map);
    drivers.push_back(*driver);
}
