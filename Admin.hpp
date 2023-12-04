#include <string>
using namespace std;

class Admin{
    private:
        string name;
        string username;
        string password;
    public:
        void addManager();
        void deleteManager();
        void editManager();
};
