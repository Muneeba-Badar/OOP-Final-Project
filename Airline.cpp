
#include <iostream>
#include <map>
#include "Airline.hpp"
using namespace std;

int Airline::autoIncAirlineId = 0;

int Airline:: generateAirlineId()
    {
        return autoIncAirlineId++;
    }

void Airline::setConnection(SAConnection* conn){
    connection = conn;
}
void Airline::addAirline(SAConnection* conn){
    airlineID = generateAirlineId();

    cout<<"Enter the Airline Name: ";
    cin>> airlineName;
    cout << "Enter the name of The Representative (Contact Person Name): ";
    cin >> contactPersonName;
    cout<<"Enter contact information of the Airline representative ";
    cin>> phoneNumber;
    cout << "Enter Email of the Airline company  ";
    cin >> email;
    cout<<"Enter the name of city where Head Quarter is located  ";
    cin>> HQcity;
    cout<<"Enter the name of the country the Airline is from ";
    cin>> HQcountry;
 

    // insert data into the database
    cmd.setCommandText(conn, _TSA("INSERT INTO Airline (airlineID, airlineName, contactPersonName, phoneNumber, email, HQcity,HQcountry) VALUES (:1, :2, :3, :4, :5, :6, :7)"));
    // cmd.setCommandText("INSERT INTO Airport (AirportId, AirportName, Country, City) VALUES (:1, :2, :3, :4)");
    cmd.Param(1).setAsInt64() = airlineID;
    cmd.Param(2).setAsString() = SAString(_TSA(airlineName.c_str()));;
    cmd.Param(3).setAsString() = SAString(_TSA(contactPersonName.c_str()));;
    cmd.Param(4).setAsString() = SAString(_TSA(phoneNumber.c_str()));;
    cmd.Param(5).setAsString()=SAString(_TSA(email.c_str()));;
    cmd.Param(6).setAsString()=SAString(_TSA(HQcity.c_str()));;
    cmd.Param(7).setAsString()=SAString(_TSA(HQcountry.c_str()));;

    // cmd << _TSA(AirportID) << _TSA(AirportName) << _TSA(Country) << _TSA(City);
    cmd.Execute();


    cout << "Airline added successfully. ID: " << airlineID << endl;
}


void Airline:: deleteAirline(SAConnection* conn){
    int deleteAirlineid;
        cout << "Enter Id of the Airline you want to delete: ";
        cin >> deleteAirlineid;
        
        // delete data from databse
        cmd.setCommandText(conn, _TSA("DELETE FROM Airline WHERE AirlineId = :1"));
        cmd.param(1).setAsInt64()=deleteAirlineid;
        cm.Execute();

        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.RowsAffected() > 0) {
            cout << "Airline deleted successfully." << endl;
        }
        else {
            cout << "Airline not found." << endl;
        }
}

void Airline::menu(SAConnection* conn){
        int choice;
    while (true)
    {
        cout<<"What do you want to do?\n";
        cout<<"\n Menu: \n 1. Add Airline: \n 2. Delete Airline\n 3. Exit\n";
        cin >> choice;
        if(choice == 1){
            addAirline(conn);
        }
        else if(choice == 2){
            deleteAirline(conn);
        }
        else{
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}
void Airline::printAirlineDetails() const {
    // Fetch data from the database
    cmd.setCommandText(conn, _TSA("SELECT * FROM Airline WHERE AirlineID = :1"));
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Airline ID: " << cmd.Field("AirlineID").asLong() << endl;
        cout << "Airline Name: " << (string) cmd.Field("AirlineName").asString() << endl;
        cout << "Contact Person Name: " << (string) cmd.Field("Contact").asString() << endl;
        cout << "Phone Number: " << (string) cmd.Field("PhoneNumber").asString() << endl;
        cout << "Email: " << (string) cmd.Field("Email").asString() << endl;
        cout << "HQ City: " << (string) cmd.Field("HQCity").asString() << endl;
        cout << "HQ Country: " << (string) cmd.Field("HQCountry").asString() << endl;
    } 
    else {
        cout << "Airline not found in the database." << endl;
    }
}

