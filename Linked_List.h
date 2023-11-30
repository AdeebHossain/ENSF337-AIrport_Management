#include <iostream>
#include "Passenger.h"
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node { 
    Passenger person;
    Node *next;
};

class linked_list {
private:
    Node *headM;
    
public:
    
    /* Constructor */
    linked_list();
    linked_list (const linked_list& source);

    /* Destructor */
    ~linked_list();
    /* Setters */  

    /* Getters */

    void add(const Passenger& passenger);
    void remove(int passengerID);
    void display_passenger()const;
};
#endif