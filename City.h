//
// Created by Tiki Lobel on 11/29/16.
//

#ifndef EX2_CITY_H
#define EX2_CITY_H
#include "TaxiCenter.h"
#include "Passenger.h"
#include "BFS.h"

class City {
private:
    TaxiCenter tc;
    BFS* map;
public:
    City(){};
    void CallTaxiCenter(Passenger p){};
    Passenger checkForPassengerCalls();
    TaxiCenter getTaxiCenter() {};
};


#endif //EX2_CITY_H
