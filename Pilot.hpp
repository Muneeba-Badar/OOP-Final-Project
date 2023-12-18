#include <string>
#include "Airline.hpp"
#include "AirlineManager.hpp"
#include "DatabaseConnection.hpp"
using namespace std;

class Pilot : public Airline, AirlineManager {
private:
    static int pilotID;
    int liscenceNo;
    string email;
    string address;
    static int autoIncGateId;
    SAConnection* connection; // Pointer to the database connection

protected:
    string pilotName;
    string phoneNumber;

public:
    int generateID();
    void addPilot(SAConnection* conn);
    void editPilot(SAConnection* conn);
    void printAllPilots(SAConnection* conn);
    void deletePilot(SAConnection* conn);
    void setConnection(SAConnection* conn);
    void menu(SAConnection* conn);
};
