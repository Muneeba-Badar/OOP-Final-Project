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
    


