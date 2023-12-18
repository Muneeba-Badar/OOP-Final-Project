#include <string>
using namespace std;
#include "DatabaseConnection.hpp"


class Admin{
    private:
        string name;
        string username;
        string password;
        SAConnection* connection; // Pointer to the database connection
    public:
        void addManager(SAConnection* conn);
        void deleteManager(SAConnection* conn);
        void editManager(SAConnection* conn);
        void setConnection(SAConnection* conn);

};