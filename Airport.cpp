
#include "Airport.hpp"

#include <iostream>
#include <map>
using namespace std;

int Airport::autoIncAirportId = 0;

int Airport::generateAirportID() {
    return autoIncAirportId++;
}



void Airport::addAirport(std::map<int, Airport> & airportMapping){
    AirportID=generateAirportID();
    cout<<"Enter the airport name: ";
    cin>>AirportName;
    cout<<"Enter the Country of the airport: ";
    cin>>Country;
    cout<<"Enter the city of the airport: ";
    cin>>City;
    airportMapping[AirportID] = *this;

    cout << "Airport added successfully. ID: " << AirportID << endl;
}

void Airport::deleteAirport(std::map<int, Airport> &airportMapping)
{
        int airportIDToDelete;
        cout << "Enter the Airport ID to delete: ";
        cin >> airportIDToDelete;

        auto it = airportMapping.find(airportIDToDelete);
        if (it != airportMapping.end())
        {
            airportMapping.erase(it);
            cout << "Airport deleted successfully." << endl;
        }
        else
        {
            cout << "Airport not found." << endl;
        }
}
