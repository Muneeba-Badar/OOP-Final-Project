#include <iostream>
#include "Runway.hpp"
#include <map>
using namespace std;

int Runway::autoIncRunwayId = 0;
int Runway::generateRunwayId() {
    return autoIncRunwayId++;
}

void Runway::addRunway(std::map<int, Runway> & Runwaymapping){
    RunwayID=generateRunwayId();
    cout<<"Enter Runway Number: ";
    cin>>RunwayNumber;
    cout<<"Enter the length of Runway: ";
    cin>>RunwayLength;
    Runwaymapping[RunwayID] = *this;

    cout << "Runway added successfully. ID: " << RunwayID << endl;
}

void Runway::deleteRunway(std::map<int, Runway> &Runwaymapping){
    int deleteRunway;
    cout<<"Enter Id of the runway you want to delete: ";
    cin>>deleteRunway;
    std::map<int, Runway>::iterator it = Runwaymapping.find(deleteRunway);
    if(it !=Runwaymapping.end()){
        Runwaymapping.erase(it);
        cout<<"Runway Deleted Succesfully"<<endl;
    }

}

