
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
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Airline (AirlineID, AirlineName, Contact, Email, HQCity, HQcountry) VALUES (:1, :2, :3, :4, :5, :6, :7)");
    cmd << airlineID << airlineName << contactPersonName << phoneNumber << email << HQcity  << HQcountry;
    cmd.Execute();

    cout << "Airline added successfully. ID: " << airlineID << endl;
}


void Airline:: deleteAirline(SAConnection* conn){
    int deleteAirlineid;
        cout << "Enter Id of the Airline you want to delete: ";
        cin >> deleteAirlineid;
        
        // delete data from databse
        SACommand cmd(&connection);
        cmd.setCommandText("DELETE FROM Airline WHERE AirlineId = :1");
        cmd << deleteAirlineid;
        
        // checks if data to be deleted is present in the database then delete else produce error message
        if (cmd.Execute() > 0) {
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
    SACommand cmd(&connection);
    cmd.setCommandText("SELECT * FROM Airline WHERE AirlineID = :1");
    cmd << airlineID;
    cmd.Execute();

    // Check if data is fetched successfully
    if (cmd.FetchNext()) {
        cout << "Airline ID: " << cmd.Field("AirlineID").asLong() << endl;
        cout << "Airline Name: " << cmd.Field("AirlineName").asString() << endl;
        cout << "Contact Person Name: " << cmd.Field("Contact").asString() << endl;
        cout << "Phone Number: " << cmd.Field("PhoneNumber").asString() << endl;
        cout << "Email: " << cmd.Field("Email").asString() << endl;
        cout << "HQ City: " << cmd.Field("HQCity").asString() << endl;
        cout << "HQ Country: " << cmd.Field("HQCountry").asString() << endl;
    } 
    else {
        cout << "Airline not found in the database." << endl;
    }
}

