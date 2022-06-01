#pragma once
#include <iostream>
using namespace std;
#include "User.h"
class Patient : public User {
    
    string CNIC;
    string email;
    public:
    Patient(string n = "", string u = "", string p = "", string c = "", string e = "") : User(n, u, p) {
        CNIC = c;
        email = e;
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
        Name = n;
    }
    void setUserName(string u) {
        userName = u;
    }
    void setPassword(string p) {
        Password = p;
    }
    void setCNIC(string c) {
        CNIC = c;
    }
    void setEmail(string e) {
        email = e;
    }

};