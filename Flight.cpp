#include <iostream>
#include <iomanip>
#include "Flight.h"
using namespace std;

/* Constrcutors */
Flight::Flight(): name("\0"), rows(0), columns(0), person() {}; 
Flight::Flight(const Flight& source) {
    this->name = source.name;
    this->rows = source.rows;
    this->columns = source.columns;
    this->person = source.person;
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

void Flight::set_person(Passenger person) {
    this->person = person;
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

Passenger Flight::get_person()const {
    return this->person;
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