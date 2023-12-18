#include "Pilot.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

int Pilot::pilotID = 0;

int Pilot:: generateID()
    {
        return pilotID++;
    }

void Pilot::setConnection(SAConnection* conn) {
    connection = conn;
}

void Pilot::addPilot(SAConnection* conn)
{

    pilotID = generateID();
    cout << "Enter pilot name: ";    
    cin >> pilotName;
    cout << "Enter Liscence Number: ";
    cin >> liscenceNo;
    cout << "Enter the phone number of the contact person: ";
    cin >> phoneNumber;
    cout << "Enter the email address: ";
    cin >> email;
    cout << "Enter the Address: ";
    cin >> address;
    SACommand cmd(conn, _TSA("INSERT INTO Pilot (pilotID, liscenceNo, email, address, pilotName, phoneNumber) VALUES (:1, :2,:3,:4,:5,:6)"));
    // cmd.setCommandText("INSERT INTO Airport (AirportId, AirportName, Country, City) VALUES (:1, :2, :3, :4)");
    cmd.Param(1).setAsInt64() = pilotID;
    cmd.Param(2).setAsInt64() = liscenceNo;
    cmd.Param(3).setAsString() = SAString(_TSA(email.c_str()));
    cmd.Param(4).setAsString() = SAString(_TSA(address.c_str()));
    cmd.Param(5).setAsString() = SAString(_TSA(pilotName.c_str()));
    cmd.Param(6).setAsString() = SAString(_TSA(phoneNumber.c_str()));
  
    cmd.Execute();

    cout << "Pilot added successfully. ID: " << pilotID << endl;
}

void Pilot::editPilot(SAConnection* conn) {
    setConnection(conn);

    int pilotIdToEdit;
    cout << "Enter the Pilot ID to edit: ";
    cin >> pilotIdToEdit;
    SACommand cmd(conn, _TSA("SELECT * FROM Pilots WHERE PilotID = :1"));


    SACommand cmd(connection);
    cmd.setCommandText();
    cmd.Param(1).setAsLong() = pilotIdToEdit;

    try {
        cmd.Execute();

        if (cmd.FetchNext()) {
            // Pilot found, allow editing
            cout << "Editing details for pilot with ID " << pilotIdToEdit << endl;

            cout << "Existing Details:" << endl;
            cout << "1. Name: " << (string) cmd.Field("PilotName").asString() << endl;
            cout << "2. Liscence Number: " << (string) cmd.Field("LiscenceNo").asLong() << endl;
            cout << "3. Phone Number: "<< (string) cmd.Field("PhoneNumber").asString() << endl;
            cout << "4. Email: " << (string) cmd.Field("Email").asString() << endl;
            cout << "5. Address: " << (string) cmd.Field("Address").asString() << endl;

            // Prompt user for the field to edit
            int choice;
            cout << "Enter the number of the field to edit (or 0 to exit): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    cin >> (string) cmd.Field("PilotName").asString();
                    break;
                case 2:
                    cout << "Enter new liscence number: ";
                    cin >> (string) cmd.Field("LiscenceNo").asLong();
                    break;
                case 3:
                    cout << "Enter new phone number: ";
                    cin >> (string) cmd.Field("PhoneNumber").asString();
                    break;
                case 4:
                    cout << "Enter new email: ";
                    cin >> (string) cmd.Field("Email").asString();
                    break;
                case 5:
                    cout << "Enter new address: ";
                    cin >> (string) cmd.Field("Address").asString();
                    break;
                case 0:
                    cout << "Exiting edit mode." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }

            // Update the pilot in the database
            cmd.setCommandText("UPDATE Pilots SET PilotName=:1, LiscenceNo=:2, PhoneNumber=:3, Email=:4, Address=:5 WHERE PilotID=:6");
            cmd.Param(6).setAsLong() = pilotIdToEdit;

            try {
                cmd.Execute();
                cout << "Pilot edited successfully." << endl;
            } catch (SAException& ex) {
                cout << "Error updating pilot: " << ex.ErrText().GetMultiByteChars() << endl;
            }

        } else {
            cout << "Pilot not found." << endl;
        }

    } catch (SAException& ex) {
        cout << "Error fetching pilot details: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}

void Pilot::deletePilot(SAConnection* conn) {
    try {
        int pilotIDToDelete;
        cout << "Enter the Pilot ID to delete: ";
        cin >> pilotIDToDelete;

        SACommand cmd(conn, _TSA("DELETE FROM Pilot WHERE pilotID = :1"));
        cmd.Param(1).setAsInt64() = pilotIDToDelete;  // Set the parameter value

        cmd.Execute();



        if ( cmd.RowsAffected() > 0) {
            cout << "Pilot deleted successfully." << endl;
        } else {
            cout << "Pilot not found." << endl;
        } //check if there is change in the rows, if yes then we would know that the pilot is deleted
    }
    catch (SAException& ex){
        cerr << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}

void Pilot::menu(SAConnection* conn) {
    int choice;

    while (true) {
        // Display menu
        cout << "===== Pilot Management System =====" << endl;
        cout << "1. Add Pilot" << endl;
        cout << "2. Edit Pilot" << endl;
        cout << "3. Print All Pilots" << endl;
        cout << "4. Delete Pilot" << endl;
        cout << "5. Return to Airline Management" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPilot(conn);
                break;
            case 2:
                editPilot(conn);
                break;
            case 3:
                printAllPilots(conn);
                break;
            case 4:
                deletePilot(conn);
                break;
            case 5:
                cout << "Returning to Airline Management." << endl;
                return;  // Return from the menu to the higher-level menu or class
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Pilot::printAllPilots(SAConnection* conn) {


    SACommand cmd(conn, _TSA("Select * FROM Pilot WHERE pilotID = :1"));
    cmd.Param(1).setAsInt64() = pilotIdToEdit;


    try {
        cmd.Execute();

        while (cmd.FetchNext()) {
            int id = cmd.Field("PilotID").asLong();
            string name = (string) cmd.Field("PilotName").asString();
            int licenseNo = cmd.Field("LiscenceNo").asLong();
            string phoneNumber = (string) cmd.Field("PhoneNumber").asString();
            string email = (string) cmd.Field("Email").asString();
            string address = (string) cmd.Field("Address").asString();

            // Print the retrieved information
            cout << "Pilot ID: " << id << ", Name: " << name << ", License Number: " << licenseNo << ", Phone: " << phoneNumber
                 << ", Email: " << email << ", Address: " << address << endl;
        }
    } catch (SAException& ex) {
        cout << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }
}

// std::ostream& operator<<(std::ostream& os, const SAString& saString) {
//     os << static_cast<const char*>(saString);
//     return os;
// }

