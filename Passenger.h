#include <string>

#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger {
private:
    /* Members */
    string Fname;
    string Lname;
    string PhoneNum;
    int PID;

public:

    /* Setters */
    void set_Fname(string Fname);
    void set_Lname(string Lname);
    void set_PhoneNum(string PhoneNum);
    void set_PID(int PID);

    /* Getters */
    string get_FName()const;
    string get_LName()const;
    string get_PhoneNum()const;
    int get_PID()const;

    /* Member Functions*/
    void add_member(const int& eYUH);
    void remove_member(const int& eYUH);
    void display_passenger_info();

};
#endif