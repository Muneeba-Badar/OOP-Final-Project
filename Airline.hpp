#include <iostream>
#include <map>
#include "DatabaseConnection.hpp"

class Airline
{
    private:
        int airlineID;
        static int autoIncAirlineId;
    protected:
        std::string airlineName;
        std::string contactPersonName;
        std::string phoneNumber;
        std::string email;
        std::string HQcity;
        std::string HQcountry;
        SAConnection* connection; // Pointer to the database connection
    public:
        int generateId();
        void addAirline(SAConnection* conn);
        void printAllAirlines(SAConnection* conn);
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
};

