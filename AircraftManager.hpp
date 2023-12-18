#include <string>
using namespace std;

class AircraftManager{
    private:
        string name;
        string username;
        string password;
        virtual void menu(SAConnection* conn);

};
