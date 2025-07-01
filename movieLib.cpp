#include "movieLib.h"
#include <iostream>
#include <string>

// Movie methods
void Movie::addMovie() {
    std::cout << "Add Movie (Placeholder): Enter title, time, etc...\n";
}

void Movie::displayMovie() {
    std::cout << "\n=== Now Showing ===\n";
    std::cout << "1. Interstellar - 19:00\n";
    std::cout << "2. Inception - 21:00\n";
    std::cout << "3. The Matrix - 23:00\n";
    std::cout << "===================\n";
}

// Administrator methods

void Administrator::changePass() {
    std::string newPass;
    std::cout << "Enter new admin password: ";
    std::cin >> newPass;
    std::cout << "Password changed successfully (not really, just simulated).\n";
}

// Seat methods
Seat::Seat() {
    seatNumber = "";
    booked = false;
}

Seat::Seat(std::string number) {
    seatNumber = number;
    booked = false;
}

void Seat::bookSeat() {
    booked = true;
    std::cout << "[Seat " << seatNumber << " booked]\n";
}

bool Seat::isBooked() const {
    return booked;
}

std::string Seat::getSeatNumber() const {
    return seatNumber;
}
