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


void Pilot::addPilot(std::map<int, Pilot> &pilotMapping)
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

    // Add the Pilot to the map
    pilotMapping[pilotID] = *this;

    cout << "Pilot added successfully. ID: " << pilotID << endl;
}

void Pilot::editPilot(std::map<int, Pilot> &pilotMapping)
{
    int lineToEdit;
    cout << "Enter the Pilot ID to edit: ";
    cin >> lineToEdit;

    // Iterate over the map
    std::map<int, Pilot>::iterator it = pilotMapping.find(lineToEdit);
    if (it != pilotMapping.end())
    {
        // The pilot with the specified ID was found

        // Access the pilot object using it->second
        Pilot &pilotToEdit = it->second;

        // Now you can edit the details of the pilot
        cout << "Editing details for pilot with ID " << pilotToEdit.pilotID << endl;

        
        cout << "Existing Details:" << endl;
        cout << "1. Phone Number: " << pilotToEdit.phoneNumber << endl;
        cout << "2. Email: " << pilotToEdit.email << endl;
        cout << "3. Address: " << pilotToEdit.address << endl;

        // Prompt user for the field to edit
        int choice;
        cout << "Enter the number of the field to edit (or 0 to exit): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new phone number: ";
            cin >> pilotToEdit.pilotName;
            break;
        case 2:
            cout << "Enter new email: ";
            cin >> pilotToEdit.email;
            break;
        case 3:
            cout << "Enter new address: ";
            cin >> pilotToEdit.address;
            break;
        case 0:
            cout << "Exiting edit mode." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        cout << "Pilot edited successfully." << endl;
    }
    else
    {
        // The pilot with the specified ID was not found
        cout << "Pilot not found." << endl;
    }
}
void Pilot::printAllPilots(std::map<int, Pilot> &pilotMapping)
{
    cout << "\nAll Pilots:\n";
    for (const auto &entry : pilotMapping)
    {
        const Pilot &pilot = entry.second;
        cout << "Pilot ID: " << pilot.pilotID << "\n"
             << "Name: " << pilot.pilotName << "\n"
             << "Liscence Number: " << pilot.liscenceNo << "\n"
             << "Email: " << pilot.email << "\n"
             << "Address: " << pilot.address << "\n"
             << "Phone Number: " << pilot.phoneNumber << "\n\n";
    }
}

void Pilot::deletePilot(std::map<int, Pilot> &pilotMapping)
{
    int pilotIDToDelete;
    cout << "Enter the Pilot ID to delete: ";
    cin >> pilotIDToDelete;

    auto it = pilotMapping.find(pilotIDToDelete);
    if (it != pilotMapping.end())
    {
        pilotMapping.erase(it);
        cout << "pilot deleted successfully." << endl;
    }
    else
    {
        cout << "pilot not found." << endl;
    }
}