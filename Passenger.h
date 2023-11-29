#include <iostream>
#include "Seat.h"
using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger {
private:
    /* Members */
    string FName;
    string LName;
    string PhoneNum;
    Seat *PSeat;
    int PID;


public:
    /* Constructor */
    Passenger();
    Passenger(const Passenger& source);

    /* Destructor */
    ~Passenger();

    /* Setters */
    void set_FName(string Fname);
    void set_LName(string Lname);
    void set_PhoneNum(string PhoneNum);
    void set_PID(int PID);
    void set_PSeat(Seat* PSeat);

    /* Getters */
    string get_FName()const;
    string get_LName()const;
    string get_PhoneNum()const;
    int get_PID()const;
    Seat *get_PSeat()const;

    /* Member Functions*/
    void display_passenger_info()const;

};
#endif