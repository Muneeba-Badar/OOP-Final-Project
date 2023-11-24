#include<iostream>
#include<cstring>
#include <Airport.hpp>

class flight{
    //- private 
    // # protected
    // + public
    protected:
    string flightNumber;
    string time;
    string from_airport;
    string to_airport;
    string flightNumber;
    string flightType;
    bool isDomestic;
    private:
    int flightId;
    public:
    void addFlight();
    void deleteFlight();
    void editFlight();



};
