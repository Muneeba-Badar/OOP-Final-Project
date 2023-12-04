#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Runway{
    private:
        int RunwayID;
        int static autoIncRunwayId;
        protected:
        int RunwayNumber;
        double RunwayLength;
    public:

        void addRunway(std::map<int, Runway> & Runwaymapping);
        void deleteRunway(std::map<int, Runway> & Runwaymapping);
        int generateRunwayId();

};
