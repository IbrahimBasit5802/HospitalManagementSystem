#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Admin : public User {
    public:
    Admin(string a, string b) : User(a, b) {

    }
    
};