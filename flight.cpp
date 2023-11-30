#include "Flight.hpp"

#include <iostream>
#include <map>
using namespace std;
int flight::autoIncFlightId = 0;

int flight::generateFlightID() {
    return autoIncFlightId++;
}
void flight::addFlight(std::map<int, flight> & flightmapping){
    flightId=generateFlightID();
    cout<<"Enter the Flight number: ";
    cin>>flightNumber;
    cout<<"Enter time: ";
    cin>>time;
    cout<<"Enter the name of the country from where the flight is departuring: ";
    cin>>to_airport;
    cout<<"Enter the name of the country where the flight is arriving: ";
    cin>>from_airport;
    cout<<"What type of flight is it?";
    cin>>flightType;
    cout<<"Is the flight domestic? ";
    cin>>isDomestic;
    flightmapping[flightId] = *this;

    cout << "Flight added successfully. ID: " << flightId << endl;
}

void flight::deleteFlight(std::map<int, flight> &fligthmapping)
{
    
        int flightIDToDelete;
        cout << "Enter the Flight ID to delete: ";
        cin >> flightIDToDelete;

        auto it = fligthmapping.find(flightIDToDelete);
        if (it != fligthmapping.end())
        {
            fligthmapping.erase(it);
            cout << "Flight deleted successfully." << endl;
        }
        else
        {
            cout << "Flight not found." << endl;
        }
    }
    


void flight::editFlight(std::map<int, flight> &flightmapping)
{
    int lineToEdit;
    cout << "Enter the Flight ID to edit: ";
    cin >> lineToEdit;

    // Iterate over the map
    std::map<int, flight>::iterator it = flightmapping.find(lineToEdit);
    if (it != flightmapping.end())
    {
        // The airline with the specified ID was found

        // Access the Airline object using it->second
        flight &flightToEdit = it->second;

        // Now you can edit the details of the airline
        cout << "Editing details for Flight with ID " << flightToEdit.flightId << endl;

        
        cout << "Existing Details:" << endl;
        cout << "1. Flight Number: " << flightToEdit.flightNumber << endl;
        cout << "2. Time: " << flightToEdit.time << endl;
        cout << "3. Departure Airport: " << flightToEdit.to_airport << endl;
        cout << "4. Arrival Airport: " << flightToEdit.from_airport << endl;
        cout << "5. Type of Flight: " << flightToEdit.flightType << endl;
        cout << "6. Is the flight domestic: " << flightToEdit.isDomestic << endl;

        // Prompt user for the field to edit
        int choice;
        cout << "Enter the number of the field to edit (or 0 to exit): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new Flight Number: ";
            cin >> flightToEdit.flightNumber;
            break;
        case 2:
            cout << "Enter new Time: ";
            cin >> flightToEdit.time;
            break;
        case 3:
            cout << "Enter new departure airport: ";
            cin >> flightToEdit.from_airport;
            break;
        case 4:
            cout << "Enter new arrival airport: ";
            cin >> flightToEdit.to_airport;
            break;
        case 5:
            cout << "Enter new type of flight: ";
            cin >> flightToEdit.flightType;
            break;
        case 6:
            cout << "Is the flight domestic? ";
            cin >> flightToEdit.isDomestic;
            break;
        case 0:
            cout << "Exiting edit mode." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        cout << "Flight edited successfully." << endl;
    }
    else
    {
        // The airline with the specified ID was not found
        cout << "Flight not found." << endl;
    }
}
