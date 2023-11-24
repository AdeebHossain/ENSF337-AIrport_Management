#include <iostream>
#include "Passenger.h"
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef Passenger Passenger_list;
struct Node { 
    Passenger_list passenger;
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

    void add_passenger(const Passenger_list& passenger);
    void remove_passenger(const Passenger_list& passenger);
};
#endif