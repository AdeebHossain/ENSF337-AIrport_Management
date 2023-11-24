#include <iostream>
#include <iomanip>
#include "Passenger.h"
using namespace std;

/* Constructor */
Passenger::Passenger(): FName("\0"), LName("\0"), PhoneNum("\0"), PID(0) {}; //INCLUDE SEAT

Passenger::Passenger(const Passenger& source) {
    this->FName = source.FName;
    this->LName = source.LName;
    this->PhoneNum = source.PhoneNum;
    // this->PSeat = source.PSeat;
    this->PID = source.PID;
}

/* Destructor */
Passenger::~Passenger() {
    // delete PSeat;
}

/* Setters */
void Passenger::set_FName(string FName) {
    this->FName = FName;
}

void Passenger::set_LName(string LName) {
    this->LName = LName;
}

void Passenger::set_PhoneNum(string PhoneNum) {
    this->PhoneNum = PhoneNum;
}

// void Passenger::set_PSeat(Seat* PSeat) {
//     this->PSeat = PSeat;
// }

void Passenger::set_PID(int PID) {
    this->PID = PID;
}

/* Getters */
string Passenger::get_FName()const {
    return this->FName;
}

string Passenger::get_LName()const {
    return this->LName;
}

string Passenger::get_PhoneNum()const {
    return this->PhoneNum;
}

// Seat* Passenger::get_PSeat()const {
//     return this->PSeat;
// }

int Passenger::get_PID()const {
    return this->PID;
}

/* Member Functions*/

void Passenger::display_passenger_info(string FName, string LName, string PhoneNum, int PID) { 
    //Need to get seat info
    cout << setw(15) << left << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone";
    cout << setw(7) << "Row" << setw(8) << "Seat" << "ID" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------" << endl;
        cout << setw(15) << FName << setw(15) << LName << setw(15) << PhoneNum;
        cout << setw(7) << "ROW" << setw(8) << "COL" << PID << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}