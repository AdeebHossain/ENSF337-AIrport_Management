#include <iostream>
#include <iomanip>
#include "Passenger.h"
using namespace std;

/* Constructor */
Passenger::Passenger(): FName(NULL), LName(NULL), PhoneNum(NULL), PID(0), PSeat(nullptr) {};

Passenger::Passenger(const Passenger& source) {
    this->FName = source.FName;
    this->LName = source.LName;
    this->PhoneNum = source.PhoneNum;
    this->PID = source.PID;
    this->PSeat = source.PSeat;
}

/* Destructor */
Passenger::~Passenger() {
    delete PSeat;
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

void Passenger::set_PID(int PID) {
    this->PID = PID;
}

void Passenger::set_PSeat(Seat* PSeat) {
    this->PSeat = PSeat;
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

int Passenger::get_PID()const {
    return this->PID;
}

Seat* Passenger::get_PSeat()const {
    return this->PSeat;
}

/* Member Functions*/

void Passenger::display_passenger_info(string FName, string LName, string PhoneNum, Seat *PSeat, int PID) {
    cout << setw(15) << left << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone";
    cout << setw(7) << "Row" << setw(8) << "Seat" << "ID" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------" << endl;
        cout << setw(15) << "Your MOM" << setw(15) << "LName" << setw(15) << "PhoneNum";
        cout << setw(7) << "Row" << setw(8) << "Seat" << "PID" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}