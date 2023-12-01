#include <string>
#include "Airline.hpp"
using namespace std;
#include "AirlineManager.hpp"

class Pilot : public Airline, AirlineManager{
    private:
        int liscenceNo;
        int idCardNo;
        string email;
        string address;
    protected:
        string pilotName;
        string phoneNumber;
};