#include <iostream>
#include "Terminal.hpp"
using namespace std;

int Terminal::autoIncTerminalId = 0;
int Terminal::generateTerminalId() {
    return autoIncTerminalId++;
}

void Terminal::setConnection(SAConnection* conn){
    connection = conn;
}

void Terminal::addTerminal(SAConnection* conn){
    terminalId=generateTerminalId();

    cout<<"Enter Terminal Number: ";
    cin>>terminalNumber;
    
    // insert data into the database
    SACommand cmd(&connection);
    cmd.setCommandText("INSERT INTO Termial (TerminalID, TerminalNumber) VALUES (:1, :2)");
    cmd << terminalId << terminalNumber;
    cmd.Execute();

    cout << "Termianl added successfully. ID: " << terminalId << endl;
}

void Terminal::deleteTerminal(SAConnection* conn){
    int deleteTerminalid;
    cout << "Enter Id of the Termial you want to delete: ";
    cin >> deleteTerminalid;
    
    // delete data from databse
    SACommand cmd(&connection);
    cmd.setCommandText("DELETE FROM Termial WHERE TerminalId = :1");
    cmd << deleteTerminalid;
    
    // checks if data to be deleted is present in the database then delete else produce error message
    if (cmd.Execute() > 0) {
        cout << "Terminal deleted successfully." << endl;
    }
    else {
        cout << "Terminal not found." << endl;
    }
}

void Terminal::menu(SAConnection* conn){
    int choice;
    while (true)
    {
        cout<<"What do you want to do?\n";
        cout<<"\n Menu: \n 1. Add Terminal \n 2. Delete Terminal\n 3. Exit\n";
        cin >> choice;
        if(choice == 1){
            addTerminal(conn);
        }
        else if(TerminalChoice == 2){
            deleteTerminal(conn);
        }
        else{
            cout << "Invalid choice. Please enter a valid option.\n"
        }
    }
}

