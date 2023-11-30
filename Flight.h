#include "Linked_List.h"
#include <iostream>
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
    Flight(string Name, int num_row, int num_col);
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
    void display_seat_map()const;
    void display_list_of_passengers()const;
    void save_to_file(string file_name);

    void add_passenger();
    void remove_passenger();
};
#endif
