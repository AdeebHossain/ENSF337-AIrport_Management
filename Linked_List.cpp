#include <iostream>
#include "Linked_List.h"
using namespace std;

linked_list::linked_list(): headM(nullptr) {}; 
linked_list::linked_list(const linked_list& source) {
    headM = source.headM;
};

/* Destructors */
linked_list::~linked_list() {
    Node *temp = headM;
    Node *prev;
    while (temp != 0) {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    headM = 0;
};

void linked_list::add_passenger(const Passenger_list& PAdding) {
    // Node *new_passenger = new Node;
    // new_passenger->passenger = PAdding;

    // if (headM == 0) {
    //     new_passenger->next = headM;
    //     headM = new_passenger;
    // }
    // else {
    //     Node *before = headM;      // will point to node in front of new node
    //     Node *after = headM->next; // will be 0 or point to node after new node
    //     while(after != 0 && PAdding.get_PSeat()->get_seat_status() == '\0') {
    //         before = after;
    //         after = after->next;
    //     }
    //     new_passenger->next = after;
    //     before->next = new_passenger;
    // }
}

void linked_list::remove_passenger(const Passenger_list& PRemoving) {
    // if (headM == nullptr)
    //     return;

    // Node *doomed_node = 0;
    // if (PRemoving.get_PSeat()->get_seat_status() == '\0') {   
    //     doomed_node = headM;
    //     headM = headM->next;
    // } else {
    //     Node *before = headM;
    //     Node *maybe_doomed = headM->next;

    //     while (maybe_doomed != 0 && PRemoving.get_PSeat()->get_seat_status() == '\0') {
    //         before = maybe_doomed;
    //         maybe_doomed = maybe_doomed->next;
    //     }
    //     if (maybe_doomed != 0 && PRemoving.get_PSeat()->get_seat_status() == '\0') {
    //         doomed_node = maybe_doomed;
    //         before->next = maybe_doomed->next;
    //     }
    // }
    // delete doomed_node;
}