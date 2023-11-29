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
    Passenger_list passenger_list;
    //vector<vector<Seat>> seat_map;

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
    void set_passenger(Passenger_list passenger);

    /* Getters */
    string get_name()const;
    int get_rows()const;
    int get_columns()const;
    Passenger_list get_passenger()const;

    /* Member Functions */
    void populate_seat_map();
    void display_seat_map()const;
    void display_list_of_passengers()const;

};
#endif