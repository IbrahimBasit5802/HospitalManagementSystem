#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class User
{
protected:
    char Name[100];
    char userName[100];
    char Password[100];

public:
    User(string n = "", string u = "", string p = "")
    {
        strcpy(this->Name, n.c_str());
        strcpy(this->userName, u.c_str());
        strcpy(this->Password, p.c_str());
    }
    string getName()
    {
        return Name;
    }
    string getUserName()
    {
        return userName;
    }
    string getPassword()
    {
        return Password;
    }
    void setName(string n)
    {
        strcpy(this->Name, n.c_str());
    }
    void setUserName(string n)
    {
        strcpy(this->userName, n.c_str());
    }
    void setPassword(string p)
    {
        strcpy(this->Password, p.c_str());
    }
};