#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>  
#include <conio.h>
#include "movieLib.h"
#include "Menu.h"


using namespace std;

void aboutPage() {
    cout << "******************************************\n";
    cout << "      Welcome to Movie Ticket System      \n";
    cout << "******************************************\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
    cout << "******************************************\n";
}

void bookSeatForMovie() {
    ifstream inFile("movies.txt");
    if (!inFile) {
        cout << "Failed to open movies.txt.\n";
        return;
    }

    vector<string> movies;
    string line;
    cout << "\n--- Available Movies ---\n";

    while (getline(inFile, line)) {
        stringstream ss(line);
        string title;
        getline(ss, title, ',');
        movies.push_back(title);
    }
    inFile.close();

    if (movies.empty()) {
        cout << "No movies available.\n";
        return;
    }

    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i] << "\n";
    }

    int choice;
    cout << "Select a movie by number: ";
    cin >> choice;
    cin.ignore();

    if (choice < 1 || choice >(int)movies.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    string selectedMovie = movies[choice - 1];
    string bookingsFile = "bookings_" + selectedMovie + ".txt";

    // Load booked seats
    vector<string> bookedSeats;
    ifstream bookingsIn(bookingsFile);
    string bookedSeat;

    while (getline(bookingsIn, bookedSeat)) {
        bookedSeats.push_back(bookedSeat);
    }
    bookingsIn.close();

    cout << "\n--- Seating Chart ---\n";
    vector<string> seats = { "A1","A2","A3","A4","A5","B1","B2","B3","B4","B5", "C1", "C2", "C3", "C4", "C5", "D1", "D2", "D3", "D4", "D5"};
    for (size_t i = 0; i < seats.size(); ++i) {
        const auto& seat = seats[i];
        if (find(bookedSeats.begin(), bookedSeats.end(), seat) != bookedSeats.end()) {
            cout << "[" << seat << " X] ";
        }
        else {
            cout << "[" << seat << "  ] ";
        }

        // Print newline after every 5 seats
        if ((i + 1) % 5 == 0) {
            cout << "\n";
        }
    }

    // Select seat
    string seatChoice;
    cout << "\nEnter the seat you want to book (e.g. A3): ";
    getline(cin, seatChoice);

    if (find(bookedSeats.begin(), bookedSeats.end(), seatChoice) != bookedSeats.end()) {
        cout << "Sorry, seat " << seatChoice << " is already booked.\n";
        return;
    }

    if (find(seats.begin(), seats.end(), seatChoice) == seats.end()) {
        cout << "Invalid seat selection.\n";
        return;
    }

    // Collect payment info
    string cardNumber, customerName;
    cout << "Enter your name: ";
    getline(cin, customerName);
    cout << "Enter your card number: ";
    getline(cin, cardNumber);

    // Book the seat
    ofstream bookingsOut(bookingsFile, ios::app);
    bookingsOut << seatChoice << "\n";
    bookingsOut.close();

    cout << "Thank you, " << customerName << "! Seat " << seatChoice << " booked for " << selectedMovie << ". Payment processed.\n";
}


void Menu::displayMenu() {
    int enter;
    do {
        cout << "********* Admin Menu *********\n";
        cout << "1. Add movie\n";
        cout << "2. Display movies\n";
        cout << "3. Edit movies\n";
        cout << "4. Remove movie\n";
        cout << "5. Admin settings\n";
        cout << "6. Exit\n";
        cout << "Select: ";
        cin >> enter;
        switch (enter) {
        case 1:
            m.addMovie();
            break;
        case 2:
            m.listMovies();
            break;
        case 3:
            m.editMovie();
            break;
        case 4:
            m.removeMovie();
            break;
        case 5:
            a.changePass();
            break;
        case 6:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid input!\n";
        }
    } while (true);
}

void startMenu() 
{
    while (true)
    {
        system("cls");
        aboutPage();
        int newCheck;
        cin >> newCheck;
        if (newCheck == 1) {
            system("cls");
            cout << "1. Administrator\n";
            cout << "2. Customer\n";
            int mainCheck;
            cin >> mainCheck;
            if (mainCheck == 1) {
                Login login;
                if (login.adminLogin()) {
                    Menu am;
                    am.displayMenu();
                }
                else {
                    cout << "Permission denied!\n";
                    (void)_getch();
                }
            }
            else if (mainCheck == 2) {
                cout << "Welcome, Customer!\n";
                Movie m;
                bookSeatForMovie();
                (void)_getch();
            }
        }
        else if (newCheck == 2) {
            cout << "Exiting...\n";
            exit(0);
        }
        else {
            cout << "Invalid input!\n";
            (void)_getch();
        }
    }
}
