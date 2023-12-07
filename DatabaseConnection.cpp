#include "DatabaseConnection.hpp"

DatabaseConnection::DatabaseConnection() {
    // establish the database connection inside the constructor
    connection.Connect("MSSQL", "LAPTOP-CDQ2932B", "", "", SA_Windows_Client);
}

DatabaseConnection::~DatabaseConnection() {
    // disconnect the database connection when the object is destroyed
    connection.Disconnect();
}

void DatabaseConnection::executeQuery(const std::string& query){
    SACommand cmd(&connect); // Create a command object associated with the connection
    cmd.setCommandText(query.c_str());
    cmd.Execute();
}