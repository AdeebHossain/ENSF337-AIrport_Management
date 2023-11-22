#ifndef SEAT_H
#define SEAT_H
class Seat {
private:
    /* Members */
    int row;
    char column;

public:
    /* Setters */
    void set_row(int row);
    void set_column(char column);

    /* Getters */
    int get_row()const;
    char get_column()const;

    /*Member Functions*/
    

};
#endif