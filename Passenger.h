#include <iostream>
#include <string>
#include <cassert>
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
    int PID;
    Seat *PSeat;

public:
    /* Constructor */
    Passenger();
    Passenger(const Passenger& source);

    /* Destructor */
    ~Passenger();

    /* Setters */
    void set_Fname(string Fname);
    void set_Lname(string Lname);
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
    void add_passenger(const Passenger& person);
    void remove_passenger(const Passenger& person);
    void display_passenger_info(string FName, string LName, string PhoneNum, Seat *PSeat, int PID);

};
#endif