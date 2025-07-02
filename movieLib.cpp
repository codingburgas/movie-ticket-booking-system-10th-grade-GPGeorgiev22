#include "movieLib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void Movie::addMovie() {
    std::ofstream outFile("movies.txt", std::ios::app);
    if (!outFile) {
        std::cout << "Failed to open movies.txt for writing.\n";
        return;
    }

    std::string title, genre, language;
    int releaseYear;

    std::cin.ignore(); 
    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter language: ";
    std::getline(std::cin, language);

    std::cout << "Enter release year: ";
    std::cin >> releaseYear;

    outFile << title << "," << genre << "," << language << "," << releaseYear << "\n";
    outFile.close();

    std::cout << "Movie added successfully.\n";
}

void Movie::listMovies() {
    std::ifstream inFile("movies.txt");
    if (!inFile) {
        std::cout << "Failed to open movies.txt for reading.\n";
        return;
    }

    std::string line;
    std::cout << "\n--- Movie List ---\n";
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string title, genre, language, year;

        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, language, ',');
        std::getline(ss, year, ',');

        std::cout << "Title: " << title << "\nGenre: " << genre
            << "\nLanguage: " << language << "\nRelease Year: " << year << "\n\n";
    }

    inFile.close();
}

void Movie::removeMovie() {
    std::ifstream inFile("movies.txt");
    if (!inFile) {
        std::cerr << "Failed to open movies.txt for reading.\n";
        return;
    }

    std::vector<std::string> movies;
    std::string line, titleToRemove;

    std::cin.ignore(); 
    std::cout << "Enter the title of the movie to remove: ";
    std::getline(std::cin, titleToRemove);

    while (std::getline(inFile, line)) {
        if (line.find(titleToRemove + ",") != 0) {
            movies.push_back(line);
        }
    }
    inFile.close();

    std::ofstream outFile("movies.txt");
    if (!outFile) {
        std::cout << "Failed to open movies.txt for writing.\n";
        return;
    }

    for (const auto& movie : movies) {
        outFile << movie << "\n";
    }

    outFile.close();

    std::cout << "Movie removed successfully (if it existed).\n";
}


void Movie::editMovie() {
    std::ifstream inFile("movies.txt");
    if (!inFile) {
        std::cout << "Failed to open movies.txt for reading.\n";
        return;
    }

    std::vector<std::string> movies;
    std::string line, titleToEdit;
    bool found = false;

    std::cin.ignore();
    std::cout << "Enter the title of the movie to edit: ";
    std::getline(std::cin, titleToEdit);

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string title;
        std::getline(ss, title, ',');

        if (title == titleToEdit) {
            found = true;

            std::string newTitle, newGenre, newLanguage;
            int newReleaseYear;

            std::cout << "Enter new title: ";
            std::getline(std::cin, newTitle);
            std::cout << "Enter new genre: ";
            std::getline(std::cin, newGenre);
            std::cout << "Enter new language: ";
            std::getline(std::cin, newLanguage);
            std::cout << "Enter new release year: ";
            std::cin >> newReleaseYear;
            std::cin.ignore();

            std::stringstream newLine;
            newLine << newTitle << "," << newGenre << "," << newLanguage << "," << newReleaseYear;
            movies.push_back(newLine.str());
        }
        else {
            movies.push_back(line);
        }
    }

    inFile.close();

    if (!found) {
        std::cout << "Movie not found!\n";
        return;
    }

    std::ofstream outFile("movies.txt");
    if (!outFile) {
        std::cout << "Failed to open movies.txt for writing.\n";
        return;
    }

    for (const auto& movie : movies) {
        outFile << movie << "\n";
    }

    outFile.close();

    std::cout << "Movie updated successfully.\n";
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
