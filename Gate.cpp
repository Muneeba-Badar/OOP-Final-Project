#include "Gate.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

Gate::autoIncGateId = 0;
int Gate::generateGateID()
    {
        return autoIncGateId++;
    }

void Gate::setConnection(SAConnection* conn){
    connection = conn;
}

void Gate::addGate(SAConnection* conn)
{
    gateId=generateGateID();

    cout<<"Enter Gate Number: ";
    cin>>gateNumber;
    
    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Gate (gateID, gateNumber) VALUES (:1, :2)");
    cmd << gateID<< gateNumber;
    cmd.Execute();

    cout << "Gate added successfully. ID: " << gateId << endl;
}

}

void Gate::printAllGates(SAConnection* conn)
{
    cout << "\nAll Gates:\n";
    for (const auto &entry : GateMapping)
    {
        const Gate &Gate = entry.second;
        cout << "Gate ID: " << Gate.gateId << "\n"
             << "Gate Number: " << Gate.gateNumber << "\n\n";
    }
}

void Gate::deleteGate(SAConnection* conn)
{
    int deleteGateid;
    cout << "Enter Id of the Gate you want to delete: ";
    cin >> deleteTerminalid;
    
    // delete data from databse
    SACommand cmd(&connection);
    cmd.setCommandText("DELETE FROM Gate WHERE gateId = :1");
    cmd << deleteGateid;
    
    // checks if data to be deleted is present in the database then delete else produce error message
    if (cmd.Execute() > 0) {
        cout << "Gate deleted successfully." << endl;
    }
    else {
        cout << "Gate not found." << endl;
    }
}
