#include <iostream>
#include "Runway.hpp"
using namespace std;
#include "DatabaseConnection.hpp"  // Include the necessary header for SAConnection


int Runway::autoIncRunwayId = 0;

int Runway::generateRunwayId() {
    return autoIncRunwayId++;
}

void Runway::setConnection(SAConnection* conn) {
    connection = conn;
}

void Runway::addRunway(SAConnection* conn) {
    RunwayID = generateRunwayId();

    cout << "Enter Runway Number: ";
    cin >> RunwayNumber;
    cout << "Enter the length of Runway: ";
    cin >> RunwayLength;

    // insert data into the database
    SACommand cmd(conn);  // Use the provided connection
    cmd.setCommandText("INSERT INTO Runway (RunwayId, RunwayNumber, RunwayLength) VALUES (:1, :2, :3)");
    cmd << RunwayID << RunwayNumber << RunwayLength;
    cmd.Execute();

    cout << "Runway added successfully. ID: " << RunwayID << endl;
}

void Runway::deleteRunway(SAConnection* conn) {
    int deleteRunwayId;
    cout << "Enter Id of the runway you want to delete: ";
    cin >> deleteRunwayId;

    // delete data from database
    SACommand cmd(conn);  // Use the provided connection
    cmd.setCommandText("DELETE FROM Runway WHERE RunwayId = :1");
    cmd << deleteRunwayId;

    // checks if data to be deleted is present in the database then delete else produce error message
    if (cmd.Execute() > 0) {
        cout << "Runway deleted successfully." << endl;
    } else {
        cout << "Runway not found." << endl;
    }
}

void Runway::menu(SAConnection* conn) {
    int choice;

    while (true) {
        cout << "What do you want to do?\n";
        cout << "\n Menu: \n 1. Add Runway \n 2. Delete Runway\n 3. Exit\n";
        cin >> choice;
        if (choice == 1) {
            addRunway(conn);
        } else if (choice == 2) {
            deleteRunway(conn);
        } else if (choice == 3) {
            cout << "Exiting Program.\n";
            break;  // Exit the loop and end the program
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Runway::printRunwayDetails(SAConnection* conn) const {
    // Fetch data from the database
    SACommand cmd(connection);
    cmd.setCommandText("SELECT * FROM Runway WHERE RunwayId = :1");
    cmd << RunwayID;
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Runway ID: " << cmd.Field("RunwayId").asLong() << endl;
        cout << "Runway Number: " << cmd.Field("RunwayNumber").asString() << endl;
        cout << "Runway Length: " << cmd.Field("RunwayLength").asDouble() << endl;
        // Add additional details as needed
    } else {
        cout << "Runway not found in the database." << endl;
    }
}
