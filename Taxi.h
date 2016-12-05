
#ifndef EX2_TAXI_H
#define EX2_TAXI_H

#include <string>

class Taxi {
private:
    int cabId;
    int kmPassed;
    std::string manufacturer;
    std::string color;
    int tariff;
    int speed;
    bool luxury;


public:
    Taxi();
    Taxi(int cabId, int kmPassed, std::string manufacturer, std::string color, int tariff,
         int speed, bool luxury){};
    ~Taxi();
    void updateKms();
    int getSpeed();
    void getManu();
    int getTariff();
    int getId();
    int getKms(){};
};


#endif //EX2_TAXI_H
