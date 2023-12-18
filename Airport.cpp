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
    SACommand cmd(conn, _TSA("INSERT INTO Airport (AirportID, AirportName, Country, City) VALUES (:1, :2, :3, :4)"));
    // cmd.setCommandText("INSERT INTO Airport (AirportId, AirportName, Country, City) VALUES (:1, :2, :3, :4)");
    cmd.Param(1).setAsInt64() = AirportID;
    cmd.Param(2).setAsString() = SAString(_TSA(AirportName.c_str()));;
    cmd.Param(3).setAsString() = SAString(_TSA(Country.c_str()));;
    cmd.Param(4).setAsString() = SAString(_TSA(City.c_str()));;
    // cmd << _TSA(AirportID) << _TSA(AirportName) << _TSA(Country) << _TSA(City);
    cmd.Execute();

    // prints the confirmation message on successful storing inside the map
    cout << "Airport added successfully. ID: " << AirportID << endl;
}

void Airport::deleteAirport(SAConnection* conn) // this deletes the airports added initilially
{
        int airportIDToDelete; // the aiportId that needs to be deleted
        cout << "Enter the Airport ID to delete: ";
        cin >> airportIDToDelete; // takes input from the user

        SACommand cmd(conn, _TSA("DELETE FROM Airport WHERE AirportId = :1"));
        cmd.param(1).setAsInt64()=airportIDToDelete;
        cmd.Execute();


        // delete data from databse
     
        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.RowsAffected() > 0) {
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
