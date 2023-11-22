#include <iostream>
#include <string>
#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Airline.h"
using namespace std;

void displayTitlePage();
void displayMenu();


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

    } while (userChoice != 6);

    return 0;
}

void displayTitlePage () {
    cout << "Version: 1.0\n"
         << "Term Project - Flight Management Program in C++\n"
         << "Produced by: Aidan Huang\n"
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

