#include "Menu.h";
#include "Calendar.h";
#include <iostream>

using namespace std;


    void Menu::displayMenu() 
    {
        int choice;
        Calendar calendar;
        while (true) {
            cout << "Menu g³ówne:\n";
            cout << "1. Zobacz kalendarz\n";
            cout << "2. Wyjscie\n";
            cout << "Wybor: ";
            cin >> choice;

            switch (choice) {
            case 1:
                calendar.displayWeek();
                break;
            case 2:
                cout << "Wyjscie...\n";
                return;
            default:
                cout << "Sprobuj ponownie\n";
            }
        }
    }
