#include<iostream>
#include "Admin.hpp"
using namespace std;



void AircraftManager::menu(SAConnection* conn) {
    int choice;
    Aircraft aircraft;
    while (true) {
        cout << "What do you want to do?\n";
        cout << "\n Menu: \n 1. Go to Aircraft. \n";
        cin >> choice;
        if (choice == 1) {
          aircraft.menu(conn);
            
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
