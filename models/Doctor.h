#pragma once
#include <iostream>
#include "User.h"
#include "Feedback.h"
#include "Payment.h"
#include "Date.h"
using namespace std;

class Doctor : public User {
    string location;
    string hospital;
    FeedBack * feedbacks;
    int no_feedbacks;
    double hourly_charge;
    string specialization;
    int experience;
    string CNIC;
    string email;
    int rating;
    Payment * payments;
    int no_payments;
    Date *available_times;
    int no_times;
    public:
    Doctor(string n = "", string u = "", string p = "", string c = "", string em = "", string h = "", string l = "", string s = "", int e = 0, double h_c = 0.0) : User(n, u, p) {
        CNIC = c;
        hospital = h;
        location = l;
        specialization = s;
        experience = e;
        hourly_charge = h_c;
        email = em;
    }
    string getCNIC() {
        return CNIC;
    }
    string getName() {
        return Name;
    }
    string getPassword() {
        return Password;
    }
    string getUserName() {
        return userName;
    }
    void setName(string n) {
        Name = n;
    }
    void setPassword(string p) {
        Password = p;
    }
    void setUserName(string u) {
        userName = u;
    }

};