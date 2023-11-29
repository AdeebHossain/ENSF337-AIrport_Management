#include <iostream>
#include <string>
#include <cassert>
#include "Flight.h"
using namespace std;

#ifndef AIRLINE_H
#define AIRLINE_H
class Airline {
private:
    Flight new_flight;
public:
/* Constructor */
    Airline();
    Airline(const Airline& source);
/* Destructor */
    ~Airline();
/* Setters */
    void set_flight(Flight new_flight);
/* Getters */
    Flight get_flight()const;
};
#endif