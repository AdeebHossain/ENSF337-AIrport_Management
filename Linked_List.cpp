#include <iostream>
#include "Linked_List.h"
using namespace std;

linked_list::linked_list() {}; 
linked_list::linked_list(const linked_list& source) {

};

/* Destructors */
linked_list::~linked_list() {
    //Blah Blah here
};

void linked_list::add_passenger(const Passenger& person) {
    Node *new_passenger = new Node;
    string userInput;

    cout << "Please enter the passenger ID: ";
    getline(cin, userInput);

   
    new_passenger->human = person;

    if (headM == 0 || person.get_PSeat()->get_seat_status() == false ) {
        new_passenger->next = headM;
        headM = new_passenger;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && person.get_PSeat()->get_seat_status() == false) {
            before = after;
            after = after->next;
        }
        new_passenger->next = after;
        before->next = new_passenger;
    }
}

void linked_list::remove_passenger(const Passenger& person) {
    if (headM == 0 || person.get_PSeat()->get_seat_status() == false)
        return;

    Node *doomed_node = 0;
    if (person.get_PSeat()->get_seat_status() == false) {   
        doomed_node = headM;
        headM = headM->next;
    } else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;

        while (maybe_doomed != 0 && person.get_PSeat()->get_seat_status() == false) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed != 0 && person.get_PSeat()->get_seat_status() == false) {
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
    delete doomed_node;
}