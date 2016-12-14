#include "City.h"
#include "Driver.h"
#include "Trip.h"
#include "Graph.h"
#include "Coordinate.h"
#include "TaxiCenter.h"

#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H


class GameFlow {
private:
City city;
    TaxiCenter tc;
public:
    GameFlow() {};
    //void doOneFrame();
    void run();
    void initialize();
    Driver createDriver(string s);
    Trip createTrip(string s);
    Graph* createGraph(string s, string s1);
    Taxi createTaxi(string s);
    Coordinate* createCoordinate(string obstacleLocation);
};


#endif //EX2_GAMEFLOW_H
