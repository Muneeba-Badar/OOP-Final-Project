#include "DatabaseConnection.hpp"

DatabaseConnection::DatabaseConnection() {
    // establish the database connection inside the constructor
    connection.Connect("MSSQL", "LAPTOP-CDQ2932B", "", "", "ACM", SA_Windows_Client);
}

DatabaseConnection::~DatabaseConnection() {
    // disconnect the database connection when the object is destroyed
    connection.Disconnect();
}

void DatabaseConnection::executeQuery(const std::string& query){
    SACommand cmd(&connection); // Create a command object associated with the connection
    cmd.setCommandText(query.c_str());
    cmd.Execute();
}

// // Overloaded << operator for SACommand
// SACommand& operator<<(SACommand& cmd, const std::string& value) {
//     cmd.Param(cmd.ParamCount()).setAsString() = value.c_str();
//     return cmd;
// }