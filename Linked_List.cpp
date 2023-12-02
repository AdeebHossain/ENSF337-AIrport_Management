#include <iostream>
#include <iomanip>
#include "Linked_List.h"
using namespace std;

linked_list::linked_list(): headM(0) {}; 

linked_list::linked_list(const linked_list& source) {
    if(source.headM == nullptr) {
        headM = nullptr;
        return;
    }

    headM = new Node;
    Node *newest_passenger = headM;
    const Node *source_node = source.headM;
    while(true) {
        newest_passenger->person = source_node->person;
        source_node = source_node->next;
        if(source_node == 0)
            break;
        newest_passenger->next = new Node;
        newest_passenger = newest_passenger->next;
    } 
    newest_passenger->next = 0;
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

Node* linked_list::get_first_node()const{
    return this->headM;
}

void linked_list::add(const Passenger& PAdding) {
    Node *new_passenger = new Node;
    new_passenger->person = PAdding;

    if (headM == 0) {
        new_passenger->next = headM;
        headM = new_passenger;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0) {
            before = after;
            after = after->next;
        }
        new_passenger->next = after;
        before->next = new_passenger;
    }
}

void linked_list::remove(int passengerID) {
    if (headM == nullptr) {
        cout << "DEBUGGING" << endl;
        return;
    }

    Node *doomed_node = 0;

    if (headM->person.get_PID() == passengerID) {   
        doomed_node = headM;
        headM = headM->next;
    } else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;

        while (maybe_doomed != 0 && maybe_doomed->person.get_PID() != passengerID) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        if (maybe_doomed != 0 && maybe_doomed->person.get_PID() == passengerID) {
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
    }
    delete doomed_node;
}



