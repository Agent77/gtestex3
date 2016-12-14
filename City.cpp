#include "City.h"
City::City() {

}
City::City(BFS* map) {
//    this->map = map;
}
void City::CallTaxiCenter(Passenger p) {

}
Passenger City::checkForPassengerCalls() {

}

/*void City::startTraffic() {
    int driverCount = tc.assignDrivers();
    std::vector<Trip>::iterator trip = tc.getTrips().begin();
    //loop
    for(int driver = 0; driver <driverCount; driver++) {
        //(*(trip)).getStart()
    }
    map.getpath();
}*/

/*void City::move() {
    int driverCount = tc.assignDrivers();
    std::vector<Driver> currentDrivers = tc.getDrivers();
    vector<Driver>::iterator it = tc.getDrivers().begin();
    while (it!=tc.getDrivers().end()){
        Coordinate* c = map->getNextInPath((*(it)).getTrip().getStart(),(*(it)).getTrip().getEnd());
        (*(it)).getTrip().updateStartPoint(c);
    }

}*/