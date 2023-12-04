#include <iostream>
#include <cstring>
#include <map>
using namespace std;
class Airport{
    private:
        int  AirportID;
        static int autoIncAirportId;


    protected:
        string AirportName;
        string Country;
        string City;
        

    public:
        void addAirport(std::map<int, Airport> & airportMapping);
        void deleteAirport(std::map<int, Airport> &airportMapping);
        int generateAirportID();


};

