#include "City.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

City::City() {

}

void City::CallTaxiCenter(Passenger p) {

}
Passenger City::checkForPassengerCalls() {

}


Driver City::createDriver(string s) {
    int info[6];
    string status;
    int i = 0;
    boost::char_separator<char> sep{","};
    tokenizer tok{s, sep};
    for (const auto &t : tok) {
        if(i != 2) {
            int d = boost::lexical_cast<int>(t);
            info[i] = d;
        }
        else {
            status = t;
        }
        i++;
    }
    Driver d = Driver(info[0], info[1], status[0], info[3], info[4]);
    return d;
}


Trip City::createTrip(string s) {
    //7 ints
    int i = 0;
    int place = 0;
    int value[13];

    boost::char_separator<char> sep{","};
    tokenizer tok{s, sep};
    for (const auto &t : tok) {
        value[place] = boost::lexical_cast<int>(t);
        place++;
    }
    Trip trip = Trip(value[0],value[1], value[2], value[3],
                     value[4], value[5], value[6]);
    return trip;
}

Coordinate* City::createCoordinate(string s) {
    int x = boost::lexical_cast<int>(s[0]);
    int y = boost::lexical_cast<int>(s[2]);
    Coordinate* point = new Point(x, y);
    return point;
}

Graph* City::createGraph(string s, string s1) {
    int x = boost::lexical_cast<int>(s);
    int y = boost::lexical_cast<int>(s1);
    Graph *graphPointer = new Grid(x, y);
    return graphPointer;
}

Taxi City::createTaxi(string s) {
    int id = boost::lexical_cast<int>(s[0]);
    int type = boost::lexical_cast<int>(s[2]);
    if(type == 1) {
        StandardCab t = StandardCab(id, s[4], s[6]);
        return t;
    } else {
        LuxuryCab t = LuxuryCab(id, s[4], s[6]);
        return t;
    }

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