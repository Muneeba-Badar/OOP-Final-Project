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
        void menu(SAConnection* conn);
        void printManagerDetails(SAConnection* conn) const;
        friend SACommand& operator<<(SACommand& cmd, const std::string& value);
};