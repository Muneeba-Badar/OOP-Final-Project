#include<iostream>
#include "Admin.hpp"
// #include "C:\\Users\\munee\\Downloads\\sqlapi++library\\SQLAPI\\include\\SQLAPI.h" // Include the SQLAPI++ header
using namespace std;


void GroundManager::menu(SAConnection* conn){
    int choice;
    while (true)
    {
        cout<<"Go to:\n";
        cout<<"\n Menu: \n 1. Airport:\n";
        cin >> choice;
        if(choice == 1){
           Airport airport;
          airport.menu(conn);
        }
        
        else{
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
