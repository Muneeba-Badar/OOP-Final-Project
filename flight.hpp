#include<cstring>
#include "DatabaseConnection.hpp"

class Flight{
    private:
        int flightId;
        static int autoIncFlightId;
        SAConnection* connection; // Pointer to the database connection
    protected:
        int tailNumber;
        int flightNumber;
        string date;
        string time;
        string flightStatus;
        string  from_airport;
        string to_airport;
        string flightType;
        bool isDomestic;

    public:
        void addFlight(SAConnection* conn);
        void deleteFlight(SAConnection* conn);
        int generateFlightID();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);


};


