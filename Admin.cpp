#include <iostream>
#include "Admin.hpp"
// #include "C:\\Users\\munee\\Downloads\\sqlapi++library\\SQLAPI\\include\\SQLAPI.h" // Include the SQLAPI++ header
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
    cmd.setCommandText(conn, _TSA("INSERT INTO Manager (Name, Username, Password) VALUES (:1, :2, :3)"));
    cmd.param(1).setAsString()=SAString(_TSA(name.c_str()));
    cmd.param(2).setAsString()=SAString(_TSA(username.c_str()));

    cmd.param(3).setAsString()=SAString(_TSA(password.c_str()));
    cmd.Execute();



    cmd << name << username << password;
    cmd.Execute();

    cout << "Manager Info added successfully. Username: " << username << endl;
}

void Admin::deleteManager(SAConnection* conn) {
    string uName;
    cout << "Enter the username of the manager that you wish to delete: ";
    cin >> uName;

    // Delete data from the database
    cmd.setCommandText(conn, _TSA("DELETE FROM Manager WHERE Username = :1"));
    cmd.param(1).setAsString()=SAString(_TSA(name.c_str()));
    cmd.Execute();

    if (cmd.RowsAffected() > 0) {
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
    cmd.setCommandText(conn, _TSA("SELECT * FROM Manager WHERE Username = :1"));
    cmd.Param(1).setAsString() = SAString(_TSA(username.c_str()));;

    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Manager ID: " << cmd.Field("ManagerID").asLong() << endl;
        cout << "Manager Name: " << (string) cmd.Field("Name").asString() << endl;
        cout << "Manager Username: " << (string) cmd.Field("Username").asString() << endl;
        // Add additional details as needed
    } else {
        cout << "Manager not found in the database." << endl;
    }
}

// Overloaded << operator for SACommand
SACommand& operator<<(SACommand& cmd, const std::string& value) {
    cmd.Param(cmd.ParamCount()).setAsString() = value.c_str();
    return cmd;
}