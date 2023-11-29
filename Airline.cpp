#include "Airline.h" 

/* Constructor */
Airline::Airline(): new_flight() {};
Airline::Airline(const Airline& source) {
    this->new_flight = source.new_flight;
};

/* Destructor */
Airline::~Airline() {

};

/* Setters */
void Airline::set_flight(Flight new_flight) {
    this->new_flight = new_flight;
}

/* Getters */
Flight Airline::get_flight()const {
    return this->new_flight;
}