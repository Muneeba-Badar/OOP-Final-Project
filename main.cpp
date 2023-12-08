#include "Airport.hpp"
#include "Runway.hpp"
#include "Terminal.hpp"
#include "Flight.hpp"
#include "Pilot.hpp"
#include "Gate.hpp"
#include <iostream>
#include <sqlapi.h>
using namespace std;

int main() {
    SAConnection connection; // Create an instance of SAConnection

    cout<<"What do you want to use:\n 1. Airport\n 2. Runway\n 3. Terminal\n 4. Flight \n 5. Airline\n 6. Pilot\n 7. Gate\n";
    int ChooseTable;
    cout << "Enter a number from 1 - 7 where you want to go: ";
    cin>>ChooseTable;

    try {
        // Connect to the SQLite database (replace with your database details)
        connection.Connect("MSSQL", "LAPTOP-CDQ2932B", "", "", SA_Windows_Client);
            default:
                cout << "Invalid choice. Exiting program." << endl;
        }
    catch (SAException &ex) {
        cerr << "Error: " << ex.ErrText().GetMultiByteChars() << endl;
    }

    switch (ChooseTable)
    {
    case 1:
        Airport airport;
        airport.setConnection(conn);
        airport.menu(conn);
        break;

    case 2:
        Runway runway;
        runway.setConnection(conn);
        runway.menu(conn);
        break;

    case 3:
        Terminal terminal;
        terminal.setConnection(conn):
        terminal.menu(conn);
        break;

    case 4:
        Flight flight;
        flight.setConnection(conn);
        flight.menu(conn);

    case 5:
        Airline airline;
        airline.setConnection(conn);
        airline.menu(conn);

    case 6:
        Pilot pilot;
        pilot.setConnection(conn);
        pilot.menu(conn);

    case 7:
        Gate gate;
        gate.setConnection(conn);
        gate.menu(conn);

    default:
        cout << "Invalid choice! Dismissing Program\n";
    }




/////////////////////////////////////////////////////////////////////////////////////////////////////////
    // if(ChooseTable == 1){
    //     Airport airport;
    //     int choice;
    //     cin >> choice;x  

    //     while (choice != 3)
    //     {
    //         std::cout << "\nMenu:\n1. Add Airport\n2. Delete Airport\n3. Exit\n";
    //         std::cout << "Enter your choice: ";
    //         std::cin >> choice;

    //         switch (choice) {
    //         case 1:
    //             airport.addAirport(airportMapping);
    //             break;
    //         case 2:
    //             airport.deleteAirport(airportMapping);
    //             break;
    //         case 3:
    //             std::cout << "Exiting program." << std::endl;
    //             break;
    //         default:
    //             std::cout << "Invalid choice. Please enter a valid option." << std::endl;
    //             break;
    //         }
    //     }
    // }
    // else if(ChooseTable==2){
    //         Runway runway;
    //         std::map<int, Runway> Runwaymapping;
    //         cout<<"What do you want to do?\n";
    //         cout<<"\n Menu: \n 1- Add Runway \n 2- Delete Runway\n";
    //         int runwayChoice;
    //         cin>>runwayChoice;
    //         if(runwayChoice==1){
    //             runway.addRunway(Runwaymapping);
                
    //         }
    //         else if(runwayChoice==2){
    //             runway.deleteRunway(Runwaymapping);
    //         }
    // }
    // else if(ChooseTable==3){
    //         Terminal termialObj;
    //         std::map<int, Terminal> Terminalmapping;
    //         cout<<"What do you want to do?\n";
    //         cout<<"\n Menu: \n 1- Add Terminal \n 2- Delete Terminal\n";
    //         int TerminalChoice;
    //         cin>>TerminalChoice;
    //         if(TerminalChoice==1){
    //             termialObj.addTerminal(Terminalmapping);
                
    //         }
    //         else if(TerminalChoice==2){
    //             termialObj.deleteTerminal(Terminalmapping);
    //         }
    // }
    if(ChooseTable==4){
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
            std::cout << "Exiting program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    }
    }
    if(ChooseTable==5){
    
    std::map<int, Airline> airlineMapping;
    Airline a1;

    int choice;
    do
    {
        cout << "\nMenu:\n1. Add Airline\n2. Edit Airline\n3. Print all the added airlines: \n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a1.addAirline(airlineMapping);
            break;
        case 2:
            a1.printAllAirlines(airlineMapping);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 3);
    }

    if(ChooseTable==6){
    
    std::map<int, Pilot> pilotMapping;
    Pilot p1;

    int choice;
    do
    {
        cout << "\nMenu:\n1. Add Pilot\n2. Edit Pilot\n3. Print all the added Pilots: \n1 4-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p1.addPilot(pilotMapping);
            break;
        case 2:
            p1.printAllPilots(pilotMapping);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 3);
    }

    if(ChooseTable==7){
    
    std::map<int, Gate> gateMapping;
    Gate g1;

    int choice;
    do
    {
        cout << "\nMenu:\n1. Add Gate\n2. Edit Gate\n3. Print all the added Gates: \n1 4-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g1.addGate(gateMapping);
            break;
        case 2:
            g1.printAllGates(gateMapping);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 3);
    }

     // Disconnect from the database
    connection.Disconnect();
     return 0;
}
   


