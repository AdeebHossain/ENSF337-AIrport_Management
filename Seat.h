#include <iostream>
using namespace std;

#ifndef SEAT_H
#define SEAT_H
class Seat {
private:
    /* Members */
    int row;
    char column;
    bool seat_status;

public:
    /* Constructor */
    Seat();
    Seat(const Seat& source);

    /* Destructor */
    ~Seat();

    /* Setters */
    void set_row(int row);
    void set_column(char column);
    void set_seat_status(bool seat_status);

    /* Getters */
    int get_row()const;
    char get_column()const;
    bool get_seat_status()const;
    

};
#endif