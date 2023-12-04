
#include <iostream>
#include <map>
#include "Airline.hpp"
using namespace std;

int Airline::autoIncId = 0;

int Airline:: generateId()
    {
        return autoIncId++;
    }


void Airline::addAirline(std::map<int, Airline> &airlineMapping)
{
    airlineID = generateId();
    cout << "Enter airline name: ";
    cin >> airlineName;
    cout << "Enter Contact Person name: ";
    cin >> contactPersonName;
    cout << "Enter the phone number of the contact person: ";
    cin >> phoneNumber;
    cout << "Enter the email of the contact person: ";
    cin >> email;
    cout << "Enter the Headquarter country: ";
    cin >> HQcountry;
    cout << "Enter the Headquarter City: ";
    cin >> HQcity;

    // Add the airline to the map
    airlineMapping[airlineID] = *this;

    cout << "Airline added successfully. ID: " << airlineID << endl;
}

void Airline::editAirline(std::map<int, Airline> &airlineMapping)
{
    int lineToEdit;
    cout << "Enter the Airline ID to edit: ";
    cin >> lineToEdit;

    // Iterate over the map
    std::map<int, Airline>::iterator it = airlineMapping.find(lineToEdit);
    if (it != airlineMapping.end())
    {
        // The airline with the specified ID was found

        // Access the Airline object using it->second
        Airline &airlineToEdit = it->second;

        // Now you can edit the details of the airline
        cout << "Editing details for Airline with ID " << airlineToEdit.airlineID << endl;

        
        cout << "Existing Details:" << endl;
        cout << "1. Name: " << airlineToEdit.airlineName << endl;
        cout << "2. Contact Person: " << airlineToEdit.contactPersonName << endl;
        cout << "3. Phone Number: " << airlineToEdit.phoneNumber << endl;
        cout << "4. Email: " << airlineToEdit.email << endl;
        cout << "5. HQ City: " << airlineToEdit.HQcity << endl;
        cout << "6. HQ Country: " << airlineToEdit.HQcountry << endl;

        // Prompt user for the field to edit
        int choice;
        cout << "Enter the number of the field to edit (or 0 to exit): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new airline name: ";
            cin >> airlineToEdit.airlineName;
            break;
        case 2:
            cout << "Enter new contact person name: ";
            cin >> airlineToEdit.contactPersonName;
            break;
        case 3:
            cout << "Enter new phone number: ";
            cin >> airlineToEdit.phoneNumber;
            break;
        case 4:
            cout << "Enter new email: ";
            cin >> airlineToEdit.email;
            break;
        case 5:
            cout << "Enter new HQ city: ";
            cin >> airlineToEdit.HQcity;
            break;
        case 6:
            cout << "Enter new HQ country: ";
            cin >> airlineToEdit.HQcountry;
            break;
        case 0:
            cout << "Exiting edit mode." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        cout << "Airline edited successfully." << endl;
    }
    else
    {
        // The airline with the specified ID was not found
        cout << "Airline not found." << endl;
    }
}
void Airline::printAllAirlines(std::map<int, Airline> &airlineMapping)
{
    cout << "\nAll Airlines:\n";
    for (const auto &entry : airlineMapping)
    {
        const Airline &airline = entry.second;
        cout << "Airline ID: " << airline.airlineID << "\n"
             << "Name: " << airline.airlineName << "\n"
             << "Contact Person: " << airline.contactPersonName << "\n"
             << "Phone Number: " << airline.phoneNumber << "\n"
             << "Email: " << airline.email << "\n"
             << "HQ City: " << airline.HQcity << "\n"
             << "HQ Country: " << airline.HQcountry << "\n\n";
    }
}
