#include<iostream>
#include<cstring>
#include<map>
using namespace std;


class flight{
    //- private 
    // # protected
    // + public
    protected:
    string flightNumber;
    string time;
    string from_airport;
    string to_airport;
    string flightType;
    bool isDomestic;
    private:
    int flightId;
    int static autoIncFlightId;
    public:
    void addFlight(std::map<int, flight> & flightmapping);
    void deleteFlight(std::map<int, flight> & flightmapping);
    int generateFlightID();



};


