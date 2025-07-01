#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>


using namespace std;

void aboutPage() {
    cout << "******************************************\n";
    cout << "      Welcome to Movie Ticket System      \n";
    cout << "******************************************\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
    cout << "******************************************\n";
}

void Menu::displayMenu() {
    int enter;
    do {
        cout << "********* Admin Menu *********\n";
        cout << "1. Add movie\n";
        cout << "2. Display movies\n";
        cout << "3. Admin settings\n";
        cout << "4. Exit\n";
        cout << "Select: ";
        cin >> enter;
        switch (enter) {
        case 1:
            m.addMovie();
            break;
        case 2:
            m.displayMovie();
            break;
        case 3:
            a.changePass();
            break;
        case 4:
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
                m.displayMovie();
                Seat s(std::string("A1"));
                s.bookSeat();
                cout << "Payment done! Booking confirmed.\n";
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
