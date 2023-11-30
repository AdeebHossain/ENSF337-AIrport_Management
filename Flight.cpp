#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Flight.h"
using namespace std;

/* Constructors */

Flight::Flight(): name("\0"), rows(24), columns(5), passenger_list(), seat_map() {}; 
    /* WILL BE CHANGED TO 0 WHEN WE READ FROM FILE */
Flight::Flight(string Name, int num_row, int num_col): name(Name), rows(num_row), columns(num_col), passenger_list(), seat_map() { };

Flight::Flight(const Flight& source) {
    this->name = source.name;
    this->rows = source.rows;
    this->columns = source.columns;
    this->passenger_list = source.passenger_list;
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

void Flight::display_seat_map () const{
    char letter = 'A'; 

    /*  NEED IF STATEMENT TO CHECK THE ROWS AND COLUMNS OF FLIGHT, 
        IF EITHER IS 0 IT SHOULD PRINT OUT NOTHING */
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
        for(int l = 0; l < columns; l++) {
            cout << setw(2) << "|";
            if(seat_map[k][l] == true) {
                cout << setw(2) << "X";
            } else {
                cout << setw(2) << "\0";
            }
        }

        cout << "|" << endl << "   ";
        for (int j = 0; j < columns; j++) {
            cout << "+---";
        }
        cout << "+" << endl;
    }
}

void Flight::display_list_of_passengers()const { 
    passenger_list.display_passenger();
}

void Flight::add_passenger() {
    string inputForPassenger;
    int userNumberInput;
    char seat;
    Passenger* new_passenger = new Passenger;

    while (true){
    cout << "Please enter the Passenger's ID: ";
    cin >> userNumberInput;

    if (userNumberInput < 1000 || userNumberInput > 9999){
        cout << "Invalid ID. Please enter an integer number between 1000 and 9999" << endl;
        continue;
    }

    new_passenger->set_PID(userNumberInput);
    break;
    }

    cout << "Please enter the Passenger's First Name: ";
    cin >> inputForPassenger;
    new_passenger->set_FName(inputForPassenger);

    cout << "Please enter the Passenger's Last Name: ";
    cin >> inputForPassenger;
    new_passenger->set_LName(inputForPassenger);

    cout << "Please enter the Passenger's Phone Number: ";
    cin >> inputForPassenger;
    new_passenger->set_PhoneNum(inputForPassenger);
    
    while (true){
        cout << "Enter the Passenger's desired row: ";
        cin >> userNumberInput;

        if (!cin || userNumberInput < 1 || userNumberInput > rows){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid row. Please choose a different row." << endl;
            continue;
        }

        cout << "Enter the Passenger's desired seat: ";
        cin >> seat;
        seat = toupper(seat);
        
        if (!isalpha(seat) || seat < 'A' || seat > 'A' + columns - 1){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid seat. Please choose a valid seat." << endl;
            continue;
        }
        
        if (seat_map[userNumberInput - 1][int(seat) - 65]){
            cout <<"Seat already taken. Please choose a differnt seat."<< endl;
            continue;
        }

        new_passenger->get_PSeat()->set_row(userNumberInput);
        new_passenger->get_PSeat()->set_column(seat);
        seat_map[userNumberInput - 1][int(seat) - 65] = true;
        break;
    }

    passenger_list.add(*new_passenger);
}

void Flight::remove_passenger() {
    int userInputPassengerId;
    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> userInputPassengerId;

    passenger_list.remove(userInputPassengerId);
}

/*  
    LOL, Unfortunately you can't access the linkedlist here... sorry T-T
    So this whole bottom part is not going to work, i'll help you on it
    tmr

    - Aidan 
*/

// void Flight::save_to_file(string file_name) {
//     ofstream file(file_name);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << file_name << endl;
//         return;
//     }
//     file << name << rows << columns << endl;

//     /* Need to traverse through the linked list and collect data
//      from each node and write that data into the file*/

    
//     Node* current = passenger_list.headM;
//     while(*current != 0) {
//         file << setw(20) << current->passenger_list.get_FName();
//         file << setw(20) << current->passenger.get_LName();
//         file << setw(15) << current->passenger.get_PhoneNum();
//         file << setw(4) << current->passenger.get_PSeat();
//         file << setw(5) << current->passenger.get_PID() << endl;
//         current = passenger_list->next;
//     }
        
// }
