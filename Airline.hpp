#include <iostream>
#include <cstring>
class Airport{
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
