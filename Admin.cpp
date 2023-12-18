#include <iostream>
#include <map>
#include "Admin.hpp"
#include "SQLAPI.h" // Include the SQLAPI++ header
using namespace std;

void Admin::setConnection(SAConnection* conn) {
    connection = conn;
}

void Admin::addManager(SAConnection* conn) {
    cout << "Please Enter Manager's Name: ";
    cin >> name;
    cout << "Please Enter Manager's Username: ";
    cin >> username;
    cout << "Please enter Manager's password: ";
    cin >> password;

    // Insert data into the database
    SACommand cmd(conn);
    cmd.setCommandText("INSERT INTO Manager (Name, Username, Password) VALUES (:1, :2, :3)");
    cmd << name << username << password;
    cmd.Execute();

    cout << "Manager Info added successfully. Username: " << username << endl;
}

void Admin::deleteManager(SAConnection* conn) {
    string uName;
    cout << "Enter the username of the manager that you wish to delete: ";
    cin >> uName;

    // Delete data from the database
    SACommand cmd(conn);
    cmd.setCommandText("DELETE FROM Manager WHERE Username = :1");
    cmd << uName;
    if (cmd.Execute() > 0) {
        cout << "Manager deleted successfully." << endl;
    } else {
        cout << "Manager not found." << endl;
    }
}

void Admin::menu(SAConnection* conn) {
    int choice;
    while (true) {
        cout << "What do you want to do?\n";
        cout << "\n Menu: \n 1. Add Manager \n 2. Delete Manager\n 3. Exit\n";
        cin >> choice;
        if (choice == 1) {
            addManager(conn);
        } else if (choice == 2) {
            deleteManager(conn);
        } else if (choice == 3) {
            cout << "Exiting Program.\n";
            break;  // Exit the loop and end the program
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Admin::printManagerDetails(SAConnection* conn) const {
    // Fetch data from the database
    SACommand cmd(conn);
    cmd.setCommandText("SELECT * FROM Manager WHERE Username = :1");
    cmd << username;
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Manager ID: " << cmd.Field("ManagerID").asLong() << endl;
        cout << "Manager Name: " << cmd.Field("Name").asString() << endl;
        cout << "Manager Username: " << cmd.Field("Username").asString() << endl;
        // Add additional details as needed
    } else {
        cout << "Manager not found in the database." << endl;
    }
}
