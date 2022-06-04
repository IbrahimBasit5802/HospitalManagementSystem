#pragma once
#include "Doctor.h"
#include <iostream>
using namespace std;
class Dermatologist : public Doctor{
    char specialization[100];
    public:
    Dermatologist(string n = "", string u = "", string p = "", string c = "", string em = "", string h = "", string l = "", int e = 0, double h_c = 0.0, string s = "") : Doctor(n, u, p, c, em, h, l, s, e, h_c) {
        strcpy(this->specialization, s.c_str());
    }
    string getSpecialization() {
        return specialization;
    }
    void setSpecialization(string s) {
        strcpy(specialization, s.c_str());
    }
};