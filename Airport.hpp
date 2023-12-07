#include <cstring>
#include "DatabaseConnection.hpp"
#pragma once

using namespace std;
class Airport{
    private:
        int  AirportID;
        static int autoIncAirportId;
        SAConnection* connection; // Pointer to the database connection

    protected:
        string AirportName;
        string Country;
        string City;
        

    public:
        void addAirport(SAConnection* conn);
        void deleteAirport(SAConnection* conn);
        int generateAirportID();
        void setConnection(SAConnection* conn);
        virtual void menu(SAConnection* conn);


};

