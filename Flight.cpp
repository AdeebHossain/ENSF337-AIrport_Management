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

void Flight::readFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    file >> name >> rows >> columns;
    resizing_seat_map(rows, columns);

    string line;
    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        // All lines are strictly 69 characters long
        if (line.length() < 69) {
            continue; 
        }

        // Manually parse the line
        string firstName = line.substr(0, 20);  // 20 Characters long
        string lastName = line.substr(20, 20);  // 20 Characters long
        string phoneNumber = line.substr(40, 15);  // 12 characters
        string seat = line.substr(60, 4);  // 4 characters
        int id = stoi(line.substr(64, 5));  // 5 characters

        size_t row_part = seat.find_first_not_of("0123456789");

        int row = stoi(seat.substr(0, row_part));

        char cols = seat[row_part];

        Passenger* new_passenger = new Passenger;
        new_passenger->set_FName(firstName);
        new_passenger->set_LName(lastName);
        new_passenger->set_PhoneNum(phoneNumber);
        new_passenger->set_PID(id);
        new_passenger->get_PSeat()->set_row(row);
        new_passenger->get_PSeat()->set_column(cols);
        new_passenger->get_PSeat()->set_seat_status(true);
        seat_map.at(row - 1).at(int(toupper(cols)) - 65) = true;
        
        passenger_list.add(*new_passenger);
    }
    file.close();
}

void Flight::display_seat_map () const{
    //Displays nothing when empty
    if(columns == 0 || rows == 0)
        return;

    char letter = 'A'; 

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

    for(int k = 1; k <= rows; k++) {
        cout << setw(3) << k;
        for(int l = 0; l < columns; l++) {
            cout << setw(2) << "|";
            if(seat_map.at(k-1).at(l)) {
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
    cin.ignore(); //Ignores cin from when user inputted passenger ID

    cout << "Please enter the Passenger's First Name: ";
    getline(cin, inputForPassenger);
    new_passenger->set_FName(inputForPassenger);

    cout << "Please enter the Passenger's Last Name: ";
    getline(cin, inputForPassenger);
    new_passenger->set_LName(inputForPassenger);

    while(true) {
        string first_three, second_three, third_three;
        string phone_number;
        bool invalid_num = false;
        cout << "Please enter the Passenger's Phone Number in the format ### ### ####: ";
        getline(cin, inputForPassenger);

        if(inputForPassenger.size() != 12) {
            cout << "\nInvalid Phone Number.\n";
            continue;
        }

        for(int i = 0; i < 12; i++) {
            if(inputForPassenger.at(i) != ' ')
                phone_number += inputForPassenger.at(i);
        }

        if(phone_number.size() != 10) {
            cout << "\nInvalid Phone Number.\n";
            continue;
        }

        for(int j = 0; j < 10; j++) {
            if(int(phone_number.at(j) - '0') < 0 || int(phone_number.at(j) - '0') > 9) {
                invalid_num = true;
                break;
            }
        }

        if(invalid_num) {
            cout << "Invalid Phone Number. Enter in Digits Only!\n";
        } else {
            inputForPassenger = phone_number.substr(0, 3) + "-" + phone_number.substr(3, 3) + "-" + phone_number.substr(6, 4);
            new_passenger->set_PhoneNum(inputForPassenger);
            break;
        }
    }
    
    while (true){
        //cin.ignore();
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
            cout <<"Seat already taken. Please choose a different seat."<< endl;
            continue;
        }
        new_passenger->get_PSeat()->set_row(userNumberInput);
        new_passenger->get_PSeat()->set_column(seat);
        new_passenger->get_PSeat()->set_seat_status(true);
        seat_map[userNumberInput - 1][int(seat) - 65] = true;
        break;
    }

    passenger_list.add(*new_passenger);
    cin.ignore();
}

void Flight::remove_passenger() {
    int userInputPassengerId;

    while(true) {
        cout << "Please enter the id of the passenger that needs to be removed: ";
        cin >> userInputPassengerId;
        
        if (!cin || userInputPassengerId < 10000 || userInputPassengerId > 99999) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid ID. Please enter an integer number between 10000 and 99999" << endl;
            continue;
        } 

        break;
    }

    //If there are no passengers to remove
    if(passenger_list.get_first_node() == NULL) {
        return;
    }

    for(Node *temp = passenger_list.get_first_node(); temp != NULL; temp = temp->next) {
        
        //Getting the position of the passener's seat
        int row = temp->person.get_PSeat()->get_row() - 1;
        int column = int(toupper(temp->person.get_PSeat()->get_column())) - 65;

        //Removing the 'X' in the seap map
        if(temp->person.get_PID() == userInputPassengerId) {
            seat_map.at(row).at(column) = false;
            passenger_list.remove(userInputPassengerId);
        }
    }
    cin.ignore();
}

void Flight::save_to_file(string file_name) {
    ofstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_name << endl;
        return;
    }
    file << left << setw(9) << name << setw(5) << rows << setw(8) << columns << endl;

    /* Need to traverse through the linked list and collect data
       from each node and write that data into the file */

    Node* current = passenger_list.get_first_node();
    while(current != 0) { 
        file << left << setw(20) << current->person.get_FName();
        file << setw(20) << current->person.get_LName();
        file << setw(20) << current->person.get_PhoneNum();
        if(current->person.get_PSeat()->get_row() > 9){
            file << current->person.get_PSeat()->get_row() << setw(2) << current->person.get_PSeat()->get_column();
        }
        else file << current->person.get_PSeat()->get_row() << setw(3) << current->person.get_PSeat()->get_column();
        // file << setw(5) << current->person.get_PSeat()->get_column();
        file << right << setw(5) << current->person.get_PID() << endl;
        current = current->next;
    }

    delete current;
}

void Flight::display_list_of_passengers()const{
    cout << setw(20) << left << "First Name" << setw(20) << "Last Name" << setw(15) << "Phone";
    cout << setw(7) << "Row" << setw(8) << "Seat" << "ID" << endl;

    for(const Node* current_passenger = passenger_list.get_first_node(); current_passenger != NULL; current_passenger = current_passenger->next) {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << setw(20) << current_passenger->person.get_FName() << setw(20) << current_passenger->person.get_LName() << setw(15) << current_passenger->person.get_PhoneNum();
        cout << setw(7) << current_passenger->person.get_PSeat()->get_row() << setw(8) << current_passenger->person.get_PSeat()->get_column() << current_passenger->person.get_PID();
        cout << endl;
    }

    cout << "----------------------------------------------------------------------------" << endl;
}

void Flight::resizing_seat_map(int rows, int columns) {
    seat_map.resize(rows);
    for(int j = 0; j < rows; j++) {
        seat_map.at(j).resize(columns);
    }
}
