
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
    // cin >> airlineName;
    getline(cin, airlineName);
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
