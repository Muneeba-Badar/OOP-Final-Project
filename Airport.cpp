#include "Airport.hpp"
#include <iostream>
using namespace std;

int Airport::autoIncAirportId = 0;

int Airport::generateAirportID() { // this is a function to autogenerate the primary key
    return autoIncAirportId++; // variable for PK
}

void Airport::setConnection(SAConnection* conn){
    connection = conn;
}

void Airport::addAirport(SAConnection* conn){ // this function adds airport
    AirportID = generateAirportID(); // calls the generateAirportID to autoincrement AirportID

    // from here it takes input from the user to populate all attributes of the Airport table
    cout << "Enter the airport name: ";
    cin >> AirportName;
    cout << "Enter the Country of the airport: ";
    cin >> Country;
    cout << "Enter the city of the airport: ";
    cin >> City;

    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Airport (AirportId, AirportName, Country, City) VALUES (:1, :2, :3, :4)");
    cmd << AirportID << AirportName << Country << City;
    cmd.Execute();

    // prints the confirmation message on successful storing inside the map
    cout << "Airport added successfully. ID: " << AirportID << endl;
}

void Airport::deleteAirport(SAConnection* conn) // this deletes the airports added initilially
{
        int airportIDToDelete; // the aiportId that needs to be deleted
        cout << "Enter the Airport ID to delete: ";
        cin >> airportIDToDelete; // takes input from the user

        // delete data from databse
        SACommand cmd(&connection);
        cmd.setCommandText("DELETE FROM Airport WHERE AirportId = :1");
        cmd << airportIDToDelete;
     
        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.Execute() > 0) {
            cout << "Airport deleted successfully." << endl;
        } else {
            cout << "Airport not found." << endl;
        }
}

void Airport::menu(SAConnection* conn){
    int choice;
    
    while (true)
    {
        cout << "\nMenu:\n1. Add Airport\n2. Delete Airport\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addAirport(conn);
            break;
        case 2:
            deleteAirport(conn);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }
}
