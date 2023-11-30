#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"
#include "Linked_List.h"
using namespace std;

void readFromFile(const string& fileName);

int main() {
    string file_name = "flight_info.txt";
    readFromFile(file_name);
}

void readFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    int rows, columns;
    string name;
    file >> name >> rows >> columns;
    cout << name << " " << rows << " " << columns << endl;

    // Flight flight(name, rows, columns);

    // Read passenger information
    string line;
    int lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;

        // Kept getting an error where it tried to read the first line as empty
        if (line.empty()) {
            continue;
        }

        // All lines are strictly 69 characters long
        if (line.length() < 69) { // haha funny
            cerr << "Error: Line " << lineNumber << " is too short. Length: " << line.length() << endl;
            cerr << "Line content: " << line << endl;
            continue;  // Skip to the next line
        }

        // Manually parse the line
        string firstName = line.substr(0, 20);  // 20 Characters long
        string lastName = line.substr(20, 20);  // 20 Characters long
        string phoneNumber = line.substr(40, 15);  // 12 characters
        string seat = line.substr(60, 4);  // 4 characters
        int id = stoi(line.substr(64, 5));  // 5 characters

        // Deletes the trailing spaces
        firstName.erase(firstName.find_last_not_of(" \t") + 1);
        lastName.erase(lastName.find_last_not_of(" \t") + 1);
        phoneNumber.erase(phoneNumber.find_last_not_of(" \t") + 1);
        seat.erase(seat.find_last_not_of(" \t") + 1);


        cout << "First Name: " << firstName << " Last Name: " << lastName
             << " Phone Number: " << phoneNumber << " Seat: " << seat << " ID: " << id << endl;

        size_t row_part = seat.find_first_not_of("0123456789");

        // Extract the numeric part
        int row = stoi(seat.substr(0, row_part));

        // Extract the character part
        char cols = seat[row_part];

        // Output the results
        cout << "Numeric part: " << row << endl;
        cout << "Character part: " << cols << endl;

    }

    file.close();
}