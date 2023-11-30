#include "Linked_List.h"
#include <vector>
using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H
class Flight {
private:
    /* Members */
    string name;
    int rows;
    int columns;
    linked_list passenger_list;
    bool seat_map [24][5]; 

public:
    /* Constructor */
    Flight();
    Flight(const Flight& source);

    /* Destructors */
    ~Flight();
    
    /* Setters */
    void set_name(string name);
    void set_rows(int rows);
    void set_columns(int columns);

    /* Getters */
    string get_name()const;
    int get_rows()const;
    int get_columns()const;


    /* Member Functions */
    void populate_seat_map();
    void display_seat_map()const;
    void display_list_of_passengers()const;

    void add_passenger();
    void remove_passenger();
};
#endif