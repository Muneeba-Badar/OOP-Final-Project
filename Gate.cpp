#include "Gate.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;

Gate::autoIncGateId = 0;
int Gate::generateID()
    {
        return autoIncGateId++;
    }


void Gate::addGate(std::map<int, Gate> &GateMapping)
{
    gateId = generateID();
    cout << "Enter Gate number: ";    
    cin >> gateNumber;

    // Add the Gate to the map
    GateMapping[gateId] = *this;

    cout << "Gate added successfully. ID: " << gateId << endl;
}

void Gate::printAllGates(std::map<int, Gate> &GateMapping)
{
    cout << "\nAll Gates:\n";
    for (const auto &entry : GateMapping)
    {
        const Gate &Gate = entry.second;
        cout << "Gate ID: " << Gate.gateId << "\n"
             << "Gate Number: " << Gate.gateNumber << "\n\n";
    }
}

void Gate::deleteGate(std::map<int, Gate> &GateMapping)
{
    int gateIdToDelete;
    cout << "Enter the Gate ID to delete: ";
    cin >> gateIdToDelete;

    auto it = GateMapping.find(gateIdToDelete);
    if (it != GateMapping.end())
    {
        GateMapping.erase(it);
        cout << "Gate deleted successfully." << endl;
    }
    else
    {
        cout << "Gate not found." << endl;
    }
}