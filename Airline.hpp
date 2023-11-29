#include <iostream>
#include <cstring>
#include<map>
#include <Airport.hpp>

class Airline
{
    private:
        int airlineID;
        static int autoIncId=0;
    protected:
        string airlineName;
        string contactPersonName;
        int phoneNumber;
        string email;
        string HQcity;
        string HQcountry;
    public:
        int generateId(){
            return autoIncId++;
        }
        void addAirline(std::map<int, Airline> &airlineMapping);
        void deleteAirline();
        void editAirline();
        
};
void Airline::addAirline(std::map<int, Airline> &airlineMapping){
        Airline newAirline;
        newAirline.airlineID=generateId();
        std::cout << "Enter airline name: ";
        std::cin >> newAirline.airlineName;
        std::cout << "Enter Contact Person name: ";
        std::cin>>newAirline.contactPersonName;
        std::cout<<"Enter the phone number of the contact person :";
        std::cin>>newAirline.phoneNumber;
        std::cout<<"Enter the email of the contact person:" ;
        std::cin>>newAirline.email;
        std::cout<<"Enter the Headquarter country: ";
        std::cin>>newAirline.HQcountry;
        std::cout<<"Enter the Headquarter City: ";
        std::cin>>newAirline.HQcity;
        airlineMapping[newAirline.airlineID] = newAirline;
        std::cout << "Airline added successfully. ID: " << newAirline.airlineID << std::endl;
}
void Airline::editAirline(std::map<int, Airline> &airlineMapping) {
    int lineToedit;
    cout<<"Enter the Airline ID to edit : ";
    cin>>lineToedit;
    //iterate over the map
    std::map<int, Airline>::iterator it = airlineMapping.find(lineToedit);
        if (it != airlineMapping.end()) {
        // The airline with the specified ID was found
    
        // Access the Airline object using it->second
        Airline& airlineToEdit = it->second;
    
        // Now you can edit the details of the airline
        std::cout << "Editing details for Airline with ID " << airlineToEdit.airlineID << std::endl;
    
        // Prompt the user to choose what to edit
        std::cout << "What do you want to edit?" << std::endl;
        std::cout << "1. Name\n2. Contact Person\n3. Email\n4. HQ City\n5. HQ Country\n";
        
        int choice;
        std::cin >> choice;
    
        // Modify the selected field based on user choice
        switch (choice) {
            case 1:
                std::cout << "Enter new airline name: ";
                std::cin >> airlineToEdit.airlineName;
                break;
            case 2:
                std::cout << "Enter new contact person name: ";
                std::cin >> airlineToEdit.contactPersonName;
                break;
            case 3:
                std::cout << "Enter new email: ";
                std::cin >> airlineToEdit.email;
                break;
            case 4:
                std::cout << "Enter new HQ city: ";
                std::cin >> airlineToEdit.HQcity;
                break;
            case 5:
                std::cout << "Enter new HQ country: ";
                std::cin >> airlineToEdit.HQcountry;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    
        std::cout << "Airline edited successfully." << std::endl;
    } else {
        // The airline with the specified ID was not found
        std::cout << "Airline not found." << std::endl;
    }



}

