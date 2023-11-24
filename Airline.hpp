#include <iostream>
#include <cstring>
class Airline
{
    private:
        int airlineID;
    protected:
        string airlineName;
        string contactPersonName;
        int phoneNumber;
        string email;
        string HQcity;
        string HQcountry;
    public:
        void addAirline();
        void deleteAirline();
        void editAirline();
};
