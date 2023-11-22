#ifndef FLIGHT_H
#define FLIGHT_H
class Flight {
private:
    /* Members */
    string name;
    int rows;
    int columns;

public:

    /* Setters */
    void set_name(string name);
    void set_rows(int rows);
    void set_columns(int columns);

    /* Getters */
    string get_name()const;
    int get_rows()const;
    int get_columns()const;

    /* Member Functions */
    void display_seat_map();

};
#endif