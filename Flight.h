#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include "Seat.h"
#include "Passenger.h"
using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H
class Flight {
private:
    /* Members */
    string name;
    int rows;
    int columns;
    Passenger person;

public:
    /* Constructor */
    Flight();
    Flight(const Flight& source);

    /* Destructors */
    ~Flight();
    
    /* Setters */
    void set_name(string name);
    void set_rows(int rows);
    void set_columns(int columns);
    void set_person(Passenger person);

    /* Getters */
    string get_name()const;
    int get_rows()const;
    int get_columns()const;
    Passenger get_person()const;

    /* Member Functions */
    void display_seat_map(int rows, int columns, Seat Pseat);

};
#endif