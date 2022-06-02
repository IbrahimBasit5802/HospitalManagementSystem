#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class User {
    protected:
    char Name[100];
    char userName[100];
    char Password[100];
    public:
    User(string n = "", string u = "", string p = "") {
        strcpy(this->Name,n.c_str());
        strcpy(this->userName, u.c_str());
        strcpy(this->Password, p.c_str());
    }
    virtual string getName() = 0;
    virtual string getUserName() = 0;
    virtual string getPassword() = 0;
    virtual void setName(string n) = 0;    
    virtual void setUserName(string n) = 0;
    virtual void setPassword(string p) = 0;
};