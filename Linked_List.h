#include <iostream>
#include "Passenger.h"
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node { 
    Passenger human;
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

    void add_passenger(const Passenger& person);
    void remove_passenger(const Passenger& person);
};
#endif