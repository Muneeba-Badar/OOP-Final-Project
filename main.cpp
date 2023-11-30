#include "Airport.hpp"
#include "Runway.hpp"
#include "Terminal.hpp"
#include "Flight.hpp"
#include <iostream>
#include <map>
using namespace std;

int main() {
    cout<<"What do you want to use:\n 1. Airport\n 2.Runway\n 3. Terminal\n";
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
    else if(choice1==3){
            terminal termialObj;
            std::map<int, terminal> Terminalmapping;
            cout<<"What do you want to do?\n";
            cout<<"\n Menu: \n 1- Add Terminal \n 2- Delete Terminal\n";
            int TerminalChoice;
            cin>>TerminalChoice;
            if(TerminalChoice==1){
                termialObj.addTerminal(Terminalmapping);
                
            }
            else if(TerminalChoice==2){
                termialObj.deleteTerminal(Terminalmapping);
            }


    }
    if(choice1==4){
    std::map<int, flight> flightmapping;

    flight flight1;

    int choice;
     while (choice != 3)
     {
        std::cout << "\nMenu:\n1. Add Flight\n2. Delete Flight\n3. Edit Flight\n Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            flight1.addFlight(flightmapping);
            break;
        case 2:
            flight1.deleteFlight(flightmapping);
            break;
        case 3:
            flight1.editFlight(flightmapping);
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
     }
    }
     return 0;
}
   



