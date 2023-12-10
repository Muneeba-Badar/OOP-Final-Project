#include<iostream>
#include<cstring>
#include <map>

class Gate{
    private:
        int gateId;
        static int autoIncGateId;
        SAConnection* connection; // Pointer to the database connection
    protected:
        int gateNumber;
    public:
        void addGate(SAConnection* conn);
        void deleteGate(SAConnection* conn);
      
        int generateID();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
        void printGateDetails();

};
