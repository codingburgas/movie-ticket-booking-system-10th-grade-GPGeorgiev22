#pragma once
#include <string>


class Movie {
public:
    void addMovie();
    void listMovies();
    void removeMovie();
    void editMovie();
};

class Administrator {
public:
    void changePass();
};

class Seat {
private:
    std::string seatNumber;
    bool booked;
public:
    Seat();                            
    Seat(std::string number);          
    void bookSeat();                   
    bool isBooked() const;            
    std::string getSeatNumber() const; 
};