#include <string>
using namespace std;

class Admin{
    private:
        string name;
        string username;
        string password;
    public:
        virtual void addManager(std::map<int, Manager> &ManagerMapping);
        virtual void deleteManager(std::map<int, Manager> &ManagerMapping);
        
