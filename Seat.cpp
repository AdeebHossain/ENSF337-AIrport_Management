#include "Seat.h"
using namespace std;

/* Constructor */
Seat::Seat(): row(0), column('\0'), seat_status('\0') {};
Seat::Seat(const Seat& source) {
    this->row = source.row;
    this->column = source.column;
    this->seat_status = source.seat_status;
}

/* Destructor */
Seat::~Seat() {
    
}

/* Setters */
void Seat::set_row(int row) {
    this->row = row;
}

void Seat::set_column(char column) {
    this->column = column;
}

void Seat::set_seat_status(char seat_status) {
    this->seat_status = seat_status;
}

/* Getters */
int Seat::get_row()const {
    return this->row;
}

char Seat::get_column()const {
    return this->column;
}

char Seat::get_seat_status()const {
    return this->seat_status;
}

/*Member Functions*/
