#include<string>
#include "DatabaseConnection.hpp"

class Flight{
    private:
        int flightId;
        static int autoIncFlightId;
        SAConnection* connection; // Pointer to the database connection
    protected:
        int tailNumber;
        int flightNumber;
        std::string date;
        std::string time;
        std::string flightStatus;
        std::string from_airport;
        std::string to_airport;
        std::string flightType;
        bool isDomestic;

    public:
        void addFlight(SAConnection* conn);
        void deleteFlight(SAConnection* conn);
        int generateFlightID();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
        void printFlightDetails() const;


};


