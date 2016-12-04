#include "Passenger.h"


Passenger::Passenger(Point p, Point p2) {
    source = p;
    dest = p2;
}

int Passenger::rateDriver() {

}

Point Passenger::getSource() {
    return source;
}

Point Passenger::getDestination() {
    return dest;
}