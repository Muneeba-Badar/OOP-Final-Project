#include "C:\\Users\\munee\\Downloads\\sqlapi++library\\SQLAPI\\include\\SQLAPI.h"
#include <string>

// #include <SQLAPI.h>

class DatabaseConnection{
    private:
        // SAConnection is a class provided by the SQLAPI++ library for C++
        SAConnection connection; // creates an Object of SAConnection 
    public:
        DatabaseConnection(); // constructor
        ~DatabaseConnection(); // destructor

        void executeQuery(const std::string& query); // method for executing query

};
