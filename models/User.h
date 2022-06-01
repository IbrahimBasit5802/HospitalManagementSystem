#pragma once
#include <iostream>
using namespace std;

class User {
    protected:
    string Name;
    string userName;
    string Password;
    public:
    User(string n = "", string u = "", string p = "") {
        Name = n;
        userName = u;
        Password = p;
    }
    virtual string getName() = 0;
    virtual string getUserName() = 0;
    virtual string getPassword() = 0;
    virtual void setName(string n) = 0;    
    virtual void setUserName(string n) = 0;
    virtual void setPassword(string p) = 0;
};