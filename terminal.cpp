#include <iostream>
#include "Terminal.hpp"
#include <map>
using namespace std;

int terminal::autoIncTerminalId = 0;
int terminal::generateTerminalId() {
    return autoIncTerminalId++;
}

void terminal::addTerminal(std::map<int, terminal> & Terminalmapping){
    terminalId=generateTerminalId();
    cout<<"Enter Terminal Number: ";
    cin>>terminalNumber;
    
    Terminalmapping[terminalId] = *this;

    cout << "Termianl added successfully. ID: " << terminalId << endl;
}

void terminal::deleteTerminal(std::map<int, terminal> &Terminalmapping){
    int deleteTerminalid;
    cout<<"Enter Id of the Terminal you want to delete: ";
    cin>>deleteTerminalid;
    std::map<int, terminal>::iterator it = Terminalmapping.find(deleteTerminalid);
    if(it !=Terminalmapping.end()){
        Terminalmapping.erase(it);
        cout<<"Terminal Deleted Succesfully"<<endl;
    }

}

