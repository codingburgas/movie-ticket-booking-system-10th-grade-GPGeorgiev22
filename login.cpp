#include "login.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Login::compare(const string& a, const string& b) {
    return a == b;
}

bool Login::adminLogin() {
    string userName, pass;
    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> pass;

    string user, userPass;
    bool nCheck = false, aCheck = false;

    ifstream userData("admins.txt");
    if (!userData) {
        cout << "Cannot open file!" << endl;
        return false;
    }

    while (userData >> user >> userPass) {
        if (compare(user, userName)) {
            nCheck = true;
        }
        if (compare(userPass, pass)) {
            aCheck = true;
        }
    }
    userData.close();

    if (nCheck && aCheck) {
        cout << "Login successful!\n";
        return true;
    }
    else {
        cout << "Invalid username or password!\n";
        return false;
    }
}
