#include <iostream>
#include "Runway.hpp"
using namespace std;

int Runway::autoIncRunwayId = 0;
int Runway::generateRunwayId()
{
    return autoIncRunwayId++;
}

void Runway::setConnection(SAConnection* conn){
    connection = conn;
}

void Runway::addRunway(SAConnection* conn){
    RunwayID=generateRunwayId();

    cout<<"Enter Runway Number: ";
    cin>>RunwayNumber;
    cout<<"Enter the length of Runway: ";
    cin>>RunwayLength;

    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Runway (RunwayId, RunwayNumber, RunwayLength) VALUES (:1, :2, :3)");
    cmd << RunwayID << RunwayNumber << RunwayLength;
    cmd.Execute();

    cout << "Runway added successfully. ID: " << RunwayID << endl;
}

void Runway::deleteRunway(SAConnection* conn)
{
    int deleteRunway;
    cout<<"Enter Id of the runway you want to delete: ";
    cin>>deleteRunway;

    // delete data from databse
    SACommand cmd(&connection);
    cmd.setCommandText("DELETE FROM Runway WHERE RunwayId = :1");
    cmd << deleteRunway;
    
    // checks if data to be deleted is present in the database then delete else produce error message
    if (cmd.Execute() > 0) {
        cout << "Runway deleted successfully." << endl;
    } else {
        cout << "Runway not found." << endl;
    }

}

void Runway::menu(SAConnection* conn)
{
    int choice;
    
    while (true)
    {
        cout << "What do you want to do?\n";
        cout << "\n Menu: \n 1. Add Runway \n 2. Delete Runway\n 3. Exit\n";
        cin >> choice;
        if(choice == 1){
            addRunway(conn);
        }
        else if(choice == 2){
            deleteRunway(conn);
        }
        else if(choice == 3){
            cout << "Exiting Program.\n"; 
        }
        else{
            cout << "Invalid choice. Please enter a valid option.\n"
        }
    }
}

