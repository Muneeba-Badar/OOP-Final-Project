#include <string>
#include "Airline.hpp"
using namespace std;
#include "AirlineManager.hpp"

class Pilot : public Airline, AirlineManager{
    private:
        static int pilotID;
        int liscenceNo;
        string email;
        string address;
    protected:
        string pilotName;
        string phoneNumber;
    public:
        int generateID();
        void addPilot(std::map<int, Pilot> &pilotMapping);
        void editPilot(std::map<int, Pilot> &pilotMapping);
        void printAllPilots(std::map<int, Pilot> &pilotMapping);
};