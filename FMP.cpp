#include <iostream>
#include <string>
// #include "Seat.h"
// #include "Passenger.h"
// #include "Flight.h"
// #include "Airline.h"
using namespace std;

void displayTitlePage();
void displayMenu();
void display_seat_map ();
void display_passenger_info ();


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
        cout << "Enter your choice: (1, 2; 3, 4, 5 or 6) ";
        getline(cin, userInput);
        cout << endl;

        /*
          If input entered is not a number, display will keep repeating until
          it is a valid number. Then the while condition will handle anything 
          that isn't a number between 1-6. We'll put a switch case in after this 
          block to actually do the following thing.
        */

        try {
            userChoice = stoi(userInput); //Converts entered string into an integer
        } catch (const invalid_argument& e) { 
            userChoice = -1; //Invalid choice means userChoice will be -1 for now
        }

        switch (userChoice)
        {
        case 1:
            display_seat_map();
            cout << "\n<<< Press Return to Continue >>>\n";
            break;
        
        default:
            break;
        }
    } while (userChoice != 6);

    return 0;
}

void displayTitlePage () {
    cout << "Version: 1.0\n"
         << "Term Project - Flight Management Program in C++\n"
         << "Produced by: YOUR MOM LOL FUCK YOU AT ASS\n"
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

/* Ignore the rest of this below, it'll be moved elsewhere*/
void display_seat_map () {
    int rows = 24;
    int columns = 6;
    cout << "       Aircraft Seat Map       " << endl;
    cout << "     A   B   C   D   E   F" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "   +---+---+---+---+---+---+" << endl;
        if(i < 10) {
            cout << i << "  |   |   |   |   |   |   |" << endl;
        } else {
            cout << i << " |   |   |   |   |   |   |" << endl;
        }
        for (int j = 0; j < columns; j++) {
            
        }
    }
    cout << "   +---+---+---+---+---+---+" << endl;
}

void display_passenger_info () {

}