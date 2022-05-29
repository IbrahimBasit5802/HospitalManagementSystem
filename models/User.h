#pragma once
#include <iostream>
using namespace std;

class User {
    string Name;
    string userName;
    string Password;
    public:
    User(string n = "", string u = "", string p = "") {
        Name = n;
        userName = u;
        Password = p;
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
        Name = n;
    }
    void setUserName(string n) {
        userName = n;
    }
    void setPassword(string p) {
        Password = p;
    }
};