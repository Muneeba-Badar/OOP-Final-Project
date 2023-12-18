#include <string>
using namespace std;
class GroundManager{
    private:
        string name;
        string username;
        string password;
    public:
        virtual void menu(SAConnection* conn);

};
