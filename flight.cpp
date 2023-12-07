#include "Flight.hpp"
#include <iostream>
using namespace std;

int Flight::autoIncFlightId = 0;
int Flight::generateFlightID()
{
    return autoIncFlightId++;
}

void Flight::setConnection(SAConnection* conn){
    connection = conn;
}

void Flight::addFlight(SAConnection* conn){
    flightId = generateFlightID();

    cout<<"Enter the Flight number: ";
    cin>>flightNumber;
    cout << "Enter Date (in the format DD-MM-YYYY): ";
    cin >> date;
    cout<<"Enter time (in the format HH:MM): ";
    cin>>time;
    cout << "Enter Tail Number";
    cin >> tailNumber
    cout<<"Enter the name of the country from where the flight is departuring: ";
    cin>>to_airport;
    cout << "Enter FLight Status";
    cin >> flightStatus;
    cout<<"Enter the name of the country where the flight is arriving: ";
    cin>>from_airport;
    cout << "Enter RunwayID: "
    cin >> runwayID;
    cout << "Enter TerminalID";
    cin >> TerminalID
    cout<<"Enter Flight Type";
    cin>>flightType;
    cout<<"Is the flight domestic (answer 1 if true and 0 if false)? ";
    cin>>isDomestic;

    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Flight (FlightID, FlightNo, Date, Time, TailNumber, FlightStatus, RumwayID, TerminalID, DestinationTo, ArrivalFrom, FlightTypeID, GateID, IsDomestic) VALUES (:1, :2)");
    cmd << flightId << flightNumber << date << time << tailNumber << flightStatus << runwayID << TerminalID << to_airport << from_a ;
    cmd.Execute();

    cout << "Flight added successfully. ID: " << flightId << endl;
}

void Flight::deleteFlight(SAConnection* conn)
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
    


