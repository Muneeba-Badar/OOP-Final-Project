#include "Gate.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int Gate::autoIncGateId = 0;

int Gate::generateGateID() {
    return autoIncGateId++;
}

void Gate::setConnection(SAConnection* conn) {
    connection = conn;
}

void Gate::addGate(SAConnection* conn) {
    gateId = generateGateID();

    cout << "Enter Gate Number: ";
    cin >> gateNumber;

    // insert data into the database
    SACommand cmd(conn);
    cmd.setCommandText("INSERT INTO Gate (gateID, gateNumber) VALUES (:1, :2)");
    cmd << gateId << gateNumber;

    try {
        cmd.Execute();
        cout << "Gate added successfully. ID: " << gateId << endl;
    } catch (SAException& ex) {
        cerr << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}

void Gate::deleteGate(SAConnection* conn) {
    int deleteGateId;
    cout << "Enter Id of the Gate you want to delete: ";
    cin >> deleteGateId;

    // delete data from database
    SACommand cmd(conn);
    cmd.setCommandText("DELETE FROM Gate WHERE gateID = :1");
    cmd << deleteGateId;

    try {
        if (cmd.Execute() > 0) {
            cout << "Gate deleted successfully." << endl;
        } else {
            cout << "Gate not found." << endl;
        }
    } catch (SAException& ex) {
        cerr << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}

void Gate::menu(SAConnection* conn) {
    int choice;
    while (true) {
        cout << "What do you want to do?\n";
        cout << "\n Menu: \n 1. Add Gate \n 2. Delete Gate\n 3. Exit\n";
        cin >> choice;
        if (choice == 1) {
            addGate(conn);
        } else if (choice == 2) {
            deleteGate(conn);
        } else if (choice == 3) {
            cout << "Exiting Program.\n";
            break;  // Exit the loop and end the program
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Gate::printGateDetails(SAConnection* conn) const {
    // Fetch data from the database
    SACommand cmd(conn);
    cmd.setCommandText("SELECT * FROM Gate WHERE gateID = :1");
    cmd << gateId;

    try {
        cmd.Execute();

        if (cmd.FetchNext()) {
            cout << "Gate ID: " << cmd.Field("gateID").asLong() << endl;
            cout << "Gate Number: " << cmd.Field("gateNumber").asString() << endl;
            // Add additional details as needed
        } else {
            cout << "Gate not found in the database." << endl;
        }
    } catch (SAException& ex) {
        cerr << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}