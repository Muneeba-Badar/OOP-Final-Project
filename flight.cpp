#include "flight.hpp"
#include <iostream>
using namespace std;
#pragma once

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
    cin>> flightNumber;
    cout << "Enter Date (in the format DD-MM-YYYY): ";
    cin >> date;
    cout<<"Enter time (in the format HH:MM): ";
    cin>> time;
    cout << "Enter Tail Number";
    cin >> tailNumber;
    cout<<"Enter the name of the country where the flight is arriving: ";
    cin.getline(cin, this->to_airport);
    cout<<"Enter the name of the country where the flight is departing from: ";
    cin.getline(cin, this->from_airport);
    cout << "Enter FLight Status";
    cin.getline(cin, this->flightStatus);
    cout<<"Enter Flight Type";
    cin.getline(cin, this->flightType);
    cout<<"Is the flight domestic (answer 1 if true and 0 if false)? ";
    cin>> isDomestic;

    // insert data into the database
    SACommand cmd(conn, _TSA("INSERT INTO Flight (FlightID, FlightNo, Date, Time, TailNumber, FlightStatus, DestinationTo, ArrivalFrom, FlightType, IsDomestic) VALUES (:1, :2,:3,:4,:5,:6,:7,:8,:9,:10)"));
    // cmd.setCommandText("INSERT INTO Airport (AirportId, AirportName, Country, City) VALUES (:1, :2, :3, :4)");
    cmd.Param(1).setAsInt64() = flightId;
    cmd.Param(2).setAsInt64() =flightNumber;
    cmd.Param(3).setAsString() = SAString(_TSA(Date.c_str()));
    cmd.Param(4).setAsString() = SAString(_TSA(Time.c_str()));
    cmd.Param(5).setAsString() = SAString(_TSA(tailNumber.c_str()));
    cmd.Param(6).setAsString() = SAString(_TSA(flightStatus.c_str()));
    cmd.Param(7).setAsString() = SAString(_TSA(to_airport.c_str()));
    cmd.Param(8).setAsString() = SAString(_TSA(from_airport.c_str()));

    // cmd << _TSA(AirportID) << _TSA(AirportName) << _TSA(Country) << _TSA(City);
    cmd.Execute();


    cout << "Flight added successfully. ID: " << flightId << endl;
}

void Flight::deleteFlight(SAConnection* conn)
{

        int deleteFlightid;
        cout << "Enter Id of the Flight you want to delete: ";
        cin >> deleteFlightid;
        
        // delete data from databse
        SACommand cmd(conn, _TSA("DELETE FROM Flight WHERE FlightId = :1"));
        cmd.Param(1).setAsInt64() = deleteFlightid;  // Set the parameter value
        cmd.Execute();



        
        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.RowsAffected() > 0) {
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
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
void Flight::printFlightDetails() const {
    // Fetch data from the database
    SACommand cmd(conn, _TSA("SELECT * FROM Flight WHERE FlightID = :1"));

    
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Flight ID: " << cmd.Field("FlightID").asLong() << endl;
        cout << "Flight Number: " << (string) cmd.Field("FlightNo").asString() << endl;
        cout << "Date: " << (string) cmd.Field("Date").asString() << endl;
        cout << "Time: " << (string) cmd.Field("Time").asString() << endl;
        cout << "Tail Number: " << (string) cmd.Field("TailNumber").asString() << endl;
        cout << "Destination: " << (string) cmd.Field("DestinationTo").asString() << endl;
        cout << "Arrival From: " << (string) cmd.Field("ArrivalFrom").asString() << endl;
        cout << "Flight Status: " << (string) cmd.Field("FlightStatus").asString() << endl;
        cout << "Flight Type: " << (string) cmd.Field("FlightType").asString() << endl;
        cout << "Is Domestic: " << (cmd.Field("IsDomestic").asBool() ? "Yes" : "No") << endl;
    } 
    else {
        cout << "Flight not found in the database." << endl;
    }
}


