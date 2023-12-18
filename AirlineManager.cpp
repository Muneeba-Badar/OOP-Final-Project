#include<iostream>
#include "Admin.hpp"
// #include "C:\\Users\\munee\\Downloads\\sqlapi++library\\SQLAPI\\include\\SQLAPI.h" // Include the SQLAPI++ header
using namespace std;


void AirlineManager::menu(SAConnection* conn){
        int choice;
        Airline airline;  // Create an instance of the Airline class

    while (true)
    {
        cout<<"What do you want to Access?\n";
        cout<<"\n Menu: \n 1. Go to Airline.\n";
        cin >> choice;
        if(choice == 1){
            airline.menu(conn);
        }
        else{
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
