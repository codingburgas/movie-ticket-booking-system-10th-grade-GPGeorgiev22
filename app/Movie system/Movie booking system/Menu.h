#ifndef MENU_H
#define MENU_H

#include "MovieLib.h"
#include "Login.h"

void aboutPage();
void startMenu();

class Menu {
public:
    Movie m;
    Administrator a;

    void displayMenu();
};

#endif
