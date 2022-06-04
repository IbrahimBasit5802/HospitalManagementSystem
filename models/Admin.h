#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include <fstream>
using namespace std;

class Admin : public User {
    public:
    Admin(string a, string b) : User(a, a,  b) {

    }
    string getName() {
        return Name;
    }
    string getUserName() {
        return userName;
    }
    string getPassword() {
        return Password;
    }
 

    void setName(string n) {
        strcpy(Name, n.c_str());
    }
    void setUserName(string u) {
        strcpy(userName, u.c_str());
    }
    void setPassword(string p) {
        strcpy(Password, p.c_str());
    }

    void viewAllPatientData() {

        ifstream patients("patients.dat", ios::binary);
        if (!patients) {
            cout << "\t\t\tThere are no patients registered." << endl;
            cout << "\t\t\tPress enter to go back...";
            int c;
            cin >> c;
            return; 
        }
        Patient p;
        int i = 1;
        while(patients.read((char*)&p, sizeof(p))) {
            cout << "\t\t\tPatient " << i << ": " << endl << endl;
            cout << "\t\t\tName: " << p.getName() << endl;
            cout << "\t\t\tCNIC: " << p.getCNIC() << endl;
            cout << "\t\t\tEmail: " << p.getEmail() << endl;
            cout << endl;
            i++;

        }
        patients.close();
    }

    Admin operator=(Admin obj) {
               setName(obj.getName());
        setUserName(obj.getUserName());
        setPassword(obj.getPassword());
    }
   

    
};