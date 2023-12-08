#include <string>
#include "Airline.hpp"
using namespace std;
#include "AircraftManager.hpp"

class Aircraft:public Airline, AircraftManager{
    private:
        int tailNumber;
        static int autoIncAircraftId;
        SAConnection* connection; // Pointer to the database connection
    protected:
        string aircraftName;
        string aircraftType;
        int capacity;
    public:
        void addAircraft(SAConnection* conn);
        void deleteAircraft(SAConnection* conn);
        void editAircraft(SAConnection* conn);
        int generateID();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
        
};