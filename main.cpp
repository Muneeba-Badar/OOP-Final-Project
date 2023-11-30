#include "Airport.hpp"
#include "Runway.hpp"
#include <iostream>
#include <map>
using namespace std;

int main() {
    cout<<"What do you want to use:\n 1. Airport\n 2.Ruway\n";
    int choice1;
    cin>>choice1;
    if(choice1==1){
    std::map<int, Airport> airportMapping;
    Airport airport;

    int choice;
     while (choice != 3)
     {
        std::cout << "\nMenu:\n1. Add Airport\n2. Delete Airport\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            airport.addAirport(airportMapping);
            break;
        case 2:
            airport.deleteAirport(airportMapping);
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
     }
    }
    else if(choice1==2){
            Runway runway;
            std::map<int, Runway> Runwaymapping;
            cout<<"What do you want to do?\n";
            cout<<"\n Menu: \n 1- Add Runway \n 2- Delete Runway\n";
            int runwayChoice;
            cin>>runwayChoice;
            if(runwayChoice==1){
                runway.addRunway(Runwaymapping);
                
            }
            else if(runwayChoice==2){
                runway.deleteRunway(Runwaymapping);
            }





    }
     return 0;
}
   



