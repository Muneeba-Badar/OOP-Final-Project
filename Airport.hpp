#include <iostream>
#include <cstring>
using namespace std;
class Airport{
    private:
        int AirportID;
    protected:
        string AirportName;
        string City;
        string Country;

    public:
        void addAirport();
        void deleteAirport();


};