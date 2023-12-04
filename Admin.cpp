#include <iostream>
#include "Admin.hpp"
#include <cstring>
using namespace std;

virtual void addManager(std::map<int, Manager> &ManagerMapping){

    cout << "Please Enter Manager's Name: " << endl;
    cin >> name;
    cout << "Please Enter Manager's Username:" << endl;
    cin >> Username;
    cout << "Please enter Manager's password: " << endl;
    cin >> password;
    ManagerMapping[Username] = *this;

    cout << "Manager Infor added successfully. Username: " << Username << endl;

};
virtual void deleteManager(std::map<int, Manager> &ManagerMapping){
    string uName;
    cout << "Enter the user name of the manager that you wish to delete: " << endl;
    cin >> uName;
    std::map<int, Manager>::iterator it = Managermapping.find(uName);
    if(it !=Managermapping.end()){
        Managermapping.erase(it);
        cout<<"Manager info Deleted Succesfully"<<endl;
}
