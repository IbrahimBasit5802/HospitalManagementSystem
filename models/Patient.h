#pragma once
#include <iostream>
using namespace std;
#include "User.h"
class Patient : public User {
    
    char CNIC[100];
    char email[100];
    public:
    Patient(string n = "", string u = "", string p = "", string c = "", string e = "") : User(n, u, p) {
        strcpy(CNIC, c.c_str());

        strcpy(email, e.c_str());
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
    string getCNIC() {
        return CNIC;
    }
    string getEmail() {
        return email;
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
    void setCNIC(string c) {
        strcpy(CNIC, c.c_str());
    }
    void setEmail(string e) {
        strcpy(email, e.c_str());
    }
    void mainMenu();
    Patient operator=(Patient obj) {
        setName(obj.getName());
        setUserName(obj.getUserName());
        setPassword(obj.getPassword());
        setEmail(obj.getEmail());
        setCNIC(obj.getCNIC());
    }

};