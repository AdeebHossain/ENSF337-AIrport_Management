#include <iostream>
#include <fstream>
#include <iomanip>
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"
#include "Linked_List.h"
using namespace std;


void displayTitlePage();
void displayMenu();
int validChoice(string userInput);
void readFromFile(const string& fileName);


int main () {
    string userInput;
    string inputForPassenger;
    Flight new_flight;
    Passenger new_passenger;

    do{
        displayTitlePage();    
        cout << "<<< Press Return to Continue >>>";
        getline(cin, userInput);
        system("clear");

    } while (!userInput.empty()); //Repeats until user hits enter

    int userChoice;
    do{
        cout << endl;
        displayMenu();
        cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) ";
        getline(cin, userInput);

        /*  If input entered is not a number, display will keep repeating until
            it is a valid number. Then the while condition will handle anything 
            that isn't a number between 1-6. */
        userChoice = validChoice(userInput);
        switch (userChoice) {
        case 1:
            new_flight.display_seat_map(24, 5, new_passenger);
            cout << "\n<<< Press Return to Continue >>>";
            getline(cin, userInput);
            system("clear");
            break;
        
        case 2:
            new_flight.get_person().display_passenger_info(new_passenger.get_FName(), new_passenger.get_LName(), new_passenger.get_PhoneNum(), new_passenger.get_PID());
            cout << "\n<<< Press Return to Continue >>>";
            getline(cin, userInput);
            system("clear");
            break;

        case 3: 
            {
                // char seat;

                cout << "Please enter the Passenger's ID: ";
                getline(cin, inputForPassenger);
                new_passenger.set_PID(validChoice(inputForPassenger));

                cout << "Please enter the Passenger's First Name: ";
                getline(cin, inputForPassenger);
                new_passenger.set_FName(inputForPassenger);

                cout << "Please enter the Passenger's Last Name: ";
                getline(cin, inputForPassenger);
                new_passenger.set_LName(inputForPassenger);

                cout << "Please enter the Passenger's Phone Number: ";
                getline(cin, inputForPassenger);
                new_passenger.set_PhoneNum(inputForPassenger);

                // cout << "Enter the Passenger's desired row: ";
                // getline(cin, inputForPassenger);
                // new_passenger.get_PSeat()->set_row(validChoice(inputForPassenger));

                // cout << "Enter the Passenger's desired seat: ";
                // cin >> seat;
                // new_passenger.get_PSeat()->set_column(seat);
            }
            break;

        case 4:
            break;

        case 5:
            cout << "\nDo you want to save the data in the " << "\"flight_info.txt\"" << "? Please answer <Y or N> ";
            getline(cin, userInput);
            if(userInput == "Y" || userInput == "y") {
                cout << "\nAll the data in the passenger list was saved into the flight_info.txt." << endl;
            }
            cout << "\n<<< Press Return to Continue >>>";
            getline(cin, userInput);
            system("clear");
            break;

        default:
            break;
        }
    } while (userChoice != 6);

    cout << "\nProgram terminated.\n\n";

    return 0;
}

void displayTitlePage () {
    cout << "Version: 1.0\n"
         << "Term Project - Flight Management Program in C++\n"
         << "Produced by: Your Dad\n"
         << "Year: 2023\n\n";
}

void displayMenu () {
    cout << "Please select one the following options:\n"
         << "1. Display Flight Seat Map.\n"
         << "2. Display Passengers Information.\n"
         << "3. Add a New Passenger.\n"
         << "4. Remove an Existing Passenger\n"
         << "5. Save data\n"
         << "6. Quit.\n\n";
}

int validChoice (string userInput) {
    int userChoice;
    try {
        userChoice = stoi(userInput); //Converts entered string into an integer
    } catch (const invalid_argument& e) { 
        userChoice = -1; //Invalid choice means userChoice will be -1 for now
    }
    
    return userChoice;
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

    Flight flight(name, rows, columns);

    // Read passenger information
    string line;
    while (getline(file, line)) {

        // Kept getting an error where it tried to read the first line as empty
        if (line.empty()) {
            continue;
        }

        // All lines are strictly 69 characters long
        if (line.length() < 69) { // haha funny
            cerr << "Error: Line is too short. Length: " << line.length() << endl;
            continue; 
        }

        // Manually parse the line
        string firstName = line.substr(0, 20);  // 20 Characters long
        string lastName = line.substr(20, 20);  // 20 Characters long
        string phoneNumber = line.substr(40, 15);  // 12 characters
        string seat = line.substr(60, 4);  // 4 characters
        int id = stoi(line.substr(64, 5));  // 5 characters

        cout << "First Name: " << firstName << " Last Name: " << lastName
             << " Phone Number: " << phoneNumber << " Seat: " << seat << " ID: " << id << endl;

    }

    file.close();
}
