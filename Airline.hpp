
#include <iostream>
#include <map>

class Airline
{
private:
    int airlineID;
    static int autoIncId;
    std::string airlineName;
    std::string contactPersonName;
    int phoneNumber;
    std::string email;
    std::string HQcity;
    std::string HQcountry;
    

public:
    int generateId();
    void addAirline(std::map<int, Airline> &airlineMapping);
  
    void printAllAirlines(std::map<int, Airline> &airlineMapping);
};

