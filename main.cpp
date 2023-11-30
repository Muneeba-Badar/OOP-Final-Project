#include "Airport.hpp"
#include <iostream>
#include <map>
using namespace std;

int main() {
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

    return 0;
}

