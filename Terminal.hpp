#include<string>
#include "DatabaseConnection.hpp"

class Terminal{
    private:
        int terminalId;
        static int autoIncTerminalId;
        SAConnection* connection; // Pointer to the database connection

    protected:
        int terminalNumber;

    public:
        void addTerminal(SAConnection* conn);
        void deleteTerminal(SAConnection* conn);
        int generateTerminalId();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
        void printTerminalDetails(SAConnection* conn);
        void handleDatabaseException(const SAException& ex); //exception handling for errors
};

