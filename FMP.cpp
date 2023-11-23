#include <iostream>
#include <iomanip>
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"
using namespace std;

void displayTitlePage();
void displayMenu();
int validChoice(string userInput);


int main () {
    string userInput;

    do{
        displayTitlePage();    
        cout << "<<< Press Return to Continue >>>";
        getline(cin, userInput);

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
            //display_seat_map();
            cout << "\n<<< Press Return to Continue >>>";
            getline(cin, userInput);
            break;
        
        case 2:
            //display_passenger_info();
            cout << "\n<<< Press Return to Continue >>>";
            getline(cin, userInput);
            break;

        case 3:
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