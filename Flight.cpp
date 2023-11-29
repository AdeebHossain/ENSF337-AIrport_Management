#include <iostream>
#include <iomanip>
#include "Flight.h"
using namespace std;

/* Constrcutors */
Flight::Flight(): name("\0"), rows(0), columns(0), passenger_list() {}; 
Flight::Flight(const Flight& source) {
    this->name = source.name;
    this->rows = source.rows;
    this->columns = source.columns;
    this->passenger_list = source.passenger_list;
    //populate_seat_map();
};

/* Destructors */
Flight::~Flight() {

};

/* Setters */
void Flight::set_name(string name) {
    this->name = name;
}

void Flight::set_rows(int rows) {
    this->rows = rows;
}

void Flight::set_columns(int columns) {
    this->columns = columns;
}

void Flight::set_passenger(Passenger_list passenger) {
    this->passenger_list = passenger;
}

/* Getters */
string Flight::get_name()const {
    return this->name;
}

int Flight::get_rows()const {
    return this->rows;
}

int Flight::get_columns()const {
    return this->columns;
}

Passenger_list Flight::get_passenger()const {
    return this->passenger_list;
}

// void Flight::populate_seat_map(){
//     for (int i = 0; i < rows; i++){
//         for (int j = 0; j< columns; j++){
//             seat_map[i][j].set_seat_status('0');
//         }
//     }
// }

void Flight::display_seat_map () const{
    char letter = 'A'; //will be removed to use PSeat.get_column() since this will give a character
    cout << setw(columns + 1) << "" << setfill(' ') << setw(20) << left << "Aircraft Seat Map" << endl << "     ";
    for (int i = 0; i < columns; i++) {
        cout << setw(4) << letter;
        letter++;
    }

    cout << endl << "   ";
    for (int j = 0; j < columns; j++) {
        cout << "+---";
    }
    cout << "+" << endl;

    for(int k = 0; k < rows; k++) {
        cout << setw(3) << k;
        for(int l = 0; l <= columns; l++) {
            cout << setw(4) << "|";
        }

        cout << endl << "   ";
        for (int j = 0; j < columns; j++) {
            cout << "+---";
        }
        cout << "+" << endl;
    }
}

void Flight::display_list_of_passengers()const { 
    //Need to get seat info
    cout << setw(15) << left << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone";
    cout << setw(7) << "Row" << setw(8) << "Seat" << "ID" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------" << endl;
        cout << setw(15) << passenger_list.get_LName() << setw(15) << passenger_list.get_LName() << setw(15) << passenger_list.get_PhoneNum();
        cout << setw(7) << passenger_list.get_PSeat()->get_row() << setw(8) << passenger_list.get_PSeat()->get_column() << passenger_list.get_PID() << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}