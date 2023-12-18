#include <iostream>
#include "Terminal.hpp"
#include <map>
using namespace std;


int Terminal::autoIncTerminalId = 0;

int Terminal::generateTerminalId() {
    return autoIncTerminalId++;
}

void Terminal::setConnection(SAConnection* conn) {
    connection = conn;
}

void Terminal::addTerminal(SAConnection* conn) {
    terminalId = generateTerminalId();
    std::cout << "Enter Terminal Number: ";
    std::cin >> terminalNumber;

    // Insert the terminal details into the database using 'conn'
    SACommand cmd(conn, _TSA("INSERT INTO Terminals (ID, TerminalNumber) VALUES (:1, :2)"));


    // Use parameterized query to avoid SQL injection
    cmd.Param(1).setAsLong() = terminalId;
    cmd.Param(2).setAsLong() = terminalNumber;

    try {
        cmd.Execute();
        std::cout << "Terminal added successfully. ID: " << terminalId << std::endl;
    } catch (SAException& ex) {
        handleDatabaseException(ex);  // Updated function call
    }
}

void Terminal::deleteTerminal(SAConnection* conn) {
    int deleteTerminalId;
    std::cout << "Enter ID of the Terminal you want to delete: ";
    std::cin >> deleteTerminalId;

    // Implement the logic to delete the terminal with 'deleteTerminalId' from the database using 'connection'
    SACommand cmd(conn, _TSA("DELETE FROM Terminals WHERE ID = :1"));
    cmd.Param(1).setAsInt64() = deleteTerminalId;  // Set the parameter value

    // Use parameterized query to avoid SQL injection
    try {
        cmd.Execute();
        if (cmd.RowsAffected() > 0) {
            std::cout << "Terminal Deleted Successfully" << std::endl;
        } else {
            std::cout << "Terminal not found." << std::endl;
        }
    } catch (SAException& ex) {
        handleDatabaseException(ex);
    }
}

void Terminal::printTerminalDetails(SAConnection* conn) {
    // Select the terminal details from the database using 'connection'
    // SACommand cmd(connection);
     SACommand cmd(conn, _TSA("SELECT ID, TerminalNumber FROM Termial"));

    // Use parameterized query to avoid SQL injection


    try {
        cmd.Execute();

        while (cmd.FetchNext()) {
            int id = cmd.Field("ID").asLong();
            int terminalNumber = cmd.Field("TerminalNumber").asLong();

            // Print the retrieved information
            std::cout << "Terminal ID: " << id << ", Terminal Number: " << terminalNumber << std::endl;
        }

        // Check for errors
        if (cmd.isResultSet()) {
            std::cerr << "Error: Unable to retrieve terminal details from the database." << std::endl;
        }
    } catch (SAException& ex) {
        handleDatabaseException(ex);
    }
}

void Terminal::handleDatabaseException(const SAException& ex) {
    // Handle exceptions
    std::cerr << "Error: " << ex.ErrText().GetMultiByteChars() << std::endl;
}

void Terminal::menu(SAConnection* conn) {
    int choice;

    do {
        // Display menu
        std::cout << "===== Terminal Management System =====" << std::endl;
        std::cout << "1. Add Terminal" << std::endl;
        std::cout << "2. Delete Terminal" << std::endl;
        std::cout << "3. Print Terminal Details" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTerminal(conn);
                break;
            case 2:
                deleteTerminal(conn);
                break;
            case 3:
                printTerminalDetails(conn);
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);
}

