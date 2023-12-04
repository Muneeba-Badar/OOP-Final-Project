#include<iostream>
#include<cstring>
#include <Airport.hpp>

class terminal{
    private:
    int terminalId;
    static int autoIncTerminalId;
    protected:
    int terminalNumber;
    public:
    void addTerminal(std::map<int, terminal> & Terminalmapping);
    void deleteTerminal(std::map<int, terminal> & Terminalmapping);
    int generateTerminalId();


};
