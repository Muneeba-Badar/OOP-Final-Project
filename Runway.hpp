#include "DatabaseConnection.hpp"

class Runway{
    private:
        int RunwayID;
        static int autoIncRunwayId; // static because it needs to update the primary key so it needs to stay in scope even when the object is destroyed
        SAConnection* connection; // Pointer to the database connection

    protected:
        int RunwayNumber;
        double RunwayLength;

    public:
        void addRunway(SAConnection* conn);
        void deleteRunway(SAConnection* conn);
        int generateRunwayId();
        void setConnection(SAConnection* conn);
        void menu(SAConnection* conn);
        void printRunwayDetails(SAConnection* conn);
};
