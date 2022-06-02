#pragma once
#include <iostream>
#include "User.h"
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
   

    
};