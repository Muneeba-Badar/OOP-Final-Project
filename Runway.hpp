#include <iostream>
#include <Airport.hpp>
using namespace std;

class Runway{
    private:
        int RunwayID;
        protected:
        int RunwayNumber;
        double RunwayLength;
    public:
        void addRunway();
        void deleteRunway();
};