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
    cin >> tailNumber;
    cout<<"Enter the name of the country where the flight is arriving: ";
    cin>> to_airport;
    cout<<"Enter the name of the country where the flight is departing from: ";
    cin>> from_airport;
    cout << "Enter FLight Status";
    cin >> flightStatus;
    cout<<"Enter Flight Type";
    cin>> flightType;
    cout<<"Is the flight domestic (answer 1 if true and 0 if false)? ";
    cin>>isDomestic;

    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Flight (FlightID, FlightNo, Date, Time, TailNumber, FlightStatus, DestinationTo, ArrivalFrom, FlightType, IsDomestic) VALUES (:1, :2)");
    cmd << flightId << flightNumber << date << time << tailNumber << flightStatus  << to_airport << from_airport << flightType << isDomestic;
    cmd.Execute();

    cout << "Flight added successfully. ID: " << flightId << endl;
}

void Flight::deleteFlight(SAConnection* conn)
{
    
        int deleteFlightid;
        cout << "Enter Id of the Flight you want to delete: ";
        cin >> deleteFlightid;
        
        // delete data from databse
        SACommand cmd(&connection);
        cmd.setCommandText("DELETE FROM Flight WHERE FlightId = :1");
        cmd << deleteFlightid;
        
        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.Execute() > 0) {
            cout << "Flight deleted successfully." << endl;
        }
        else {
            cout << "Flight not found." << endl;
        }
    }
    
void Flight::menu(SAConnection* conn){
    int choice;
    while (true)
    {
        cout<<"What do you want to do?\n";
        cout<<"\n Menu: \n 1. Add Flight: \n 2. Delete Flight\n 3. Exit\n";
        cin >> choice;
        if(choice == 1){
            addFlight(conn);
        }
        else if(choice == 2){
            deleteFlight(conn);
        }
        else{
            cout << "Invalid choice. Please enter a valid option.\n"
        }
    }
}
void Flight::printFlightDetails() const {
    // Fetch data from the database
    SACommand cmd(&connection);
    cmd.setCommandText("SELECT * FROM Flight WHERE FlightID = :1");
    cmd << flightId;
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Flight ID: " << cmd.Field("FlightID").asLong() << endl;
        cout << "Flight Number: " << cmd.Field("FlightNo").asString() << endl;
        cout << "Date: " << cmd.Field("Date").asString() << endl;
        cout << "Time: " << cmd.Field("Time").asString() << endl;
        cout << "Tail Number: " << cmd.Field("TailNumber").asString() << endl;
        cout << "Destination: " << cmd.Field("DestinationTo").asString() << endl;
        cout << "Arrival From: " << cmd.Field("ArrivalFrom").asString() << endl;
        cout << "Flight Status: " << cmd.Field("FlightStatus").asString() << endl;
        cout << "Flight Type: " << cmd.Field("FlightType").asString() << endl;
        cout << "Is Domestic: " << (cmd.Field("IsDomestic").asBool() ? "Yes" : "No") << endl;
    } 
    else {
        cout << "Flight not found in the database." << endl;
    }
}


