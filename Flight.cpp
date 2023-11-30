#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Flight.h"
using namespace std;

/* Constructors */

Flight::Flight(): name("\0"), rows(0), columns(0), passenger_list(), seat_map() {}; 

Flight::Flight(string Name, int num_row, int num_col): name(Name), rows(num_row), columns(num_col), passenger_list() {
    resizing_seat_map(num_row, num_col);
};

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
            if(seat_map.at(k).at(l)) {
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

void Flight::add_passenger() {
    string inputForPassenger;
    int userNumberInput;
    char seat;
    bool is_new_passenger = true;
    Passenger* new_passenger = new Passenger;

    while (true) {
        is_new_passenger = true; //Resets flag to account for the user's next input
        cout << "Please enter the Passenger's ID: ";
        cin >> userNumberInput;

        //Validate passenger ID
        if (!cin || userNumberInput < 10000 || userNumberInput > 99999) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid ID. Please enter an integer number between 10000 and 99999" << endl;
            continue;
        } 
        
        //Checks for unique Passenger ID
        for(Node *temp = passenger_list.get_first_node(); temp != NULL; temp = temp->next) {
            if(temp->person.get_PID() == userNumberInput) {
                is_new_passenger = false;
                delete temp;
                break;
            }
        }
        
        //If Passenger ID already exists, prompts user to enter in a diff unique ID
        if(!is_new_passenger) {
            cout << "Passenger ID already exists. Please enter in a different unique Passenger ID" << endl;
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
        
        if (seat_map.at(userNumberInput - 1).at(int(seat) - 65)){
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
    Node *temp = passenger_list.get_first_node();

    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> userInputPassengerId;

    //Getting the position of the seat
    int column = int(toupper(temp->person.get_PSeat()->get_column())) - 65;
    int row = temp->person.get_PSeat()->get_row() - 1;

    //Removing the 'X' in the seap map
    for(temp = passenger_list.get_first_node(); temp != NULL; temp = temp->next) {
        if(temp->person.get_PID() == userInputPassengerId) {
            seat_map.at(row).at(column) = false;
        }
    }
    
    passenger_list.remove(userInputPassengerId);
    delete temp;
    
}

void Flight::save_to_file(string file_name) {
    ofstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_name << endl;
        return;
    }
    file << left << name << setw(5) << rows << setw(8) << columns << endl;

    /* Need to traverse through the linked list and collect data
     from each node and write that data into the file*/

    Node* current = passenger_list.get_first_node();
    while(current != 0) { 
        file << setw(20) << current->person.get_FName();
        file << setw(20) << current->person.get_LName();
        file << setw(20) << current->person.get_PhoneNum();
        file << current->person.get_PSeat()->get_row();
        file << setw(5) << current->person.get_PSeat()->get_column();
        file << setw(5) << current->person.get_PID() << endl;
        current = current->next;
    }

    delete current;
}

void Flight::display_list_of_passengers()const{
    cout << setw(15) << left << "First Name" << setw(15) << "Last Name" << setw(15) << "Phone";
    cout << setw(7) << "Row" << setw(8) << "Seat" << "ID" << endl;

    for(const Node* current_passenger = passenger_list.get_first_node(); current_passenger != NULL; current_passenger = current_passenger->next) {
        cout << "------------------------------------------------------------------" << endl;
        cout << setw(15) << current_passenger->person.get_FName() << setw(15) << current_passenger->person.get_LName() << setw(15) << current_passenger->person.get_PhoneNum();
        cout << setw(7) << current_passenger->person.get_PSeat()->get_row() << setw(8) << current_passenger->person.get_PSeat()->get_column() << current_passenger->person.get_PID();
        cout << endl;
    }

    cout << "------------------------------------------------------------------" << endl;
}

void Flight::resizing_seat_map(int rows, int columns) {
    seat_map.resize(rows);
    for(auto& row : seat_map) {
        seat_map.resize(columns);
    }
}