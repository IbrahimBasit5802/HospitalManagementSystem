#pragma once
#include <iostream>
#include "User.h"
#include "Feedback.h"
#include "Payment.h"
#include "Date.h"
#include<string.h>
using namespace std;

class Doctor : public User {
    protected:

    char location[100];
    char hospital[100];
    FeedBack * feedbacks;
    int no_feedbacks;
    double hourly_charge;
   char specialization[100];
    int experience;
    char CNIC[100];
    char email[100];
    int rating;
    Payment * payments;
    int no_payments;
    Date *available_times;
    int no_times;
    public:
    Doctor(string n = "", string u = "", string p = "", string c = "", string em = "", string h = "", string l = "", string s = "", int e = 0, double h_c = 0.0) : User(n, u, p) {
        strcpy(this->CNIC, c.c_str());
        strcpy(this->hospital, h.c_str());
        strcpy(this->location, l.c_str());
        strcpy(this->specialization, s.c_str());
        experience = e;
        hourly_charge = h_c;
        strcpy(this->email, em.c_str());
    }
    string getCNIC() {
        return CNIC;
    }

    string getEmail() {
        return email;
    }
    string getLocation() {
        return location;
    }
    string getHospital() {
        return hospital;
    }
 
    int getExperience() {
        return experience;
    }
    double getHourlyCharge() {
        return hourly_charge;
    }

    void setEmail(string e) {
        strcpy(email, e.c_str());
    }
        void setCNIC(string c) {
        strcpy(CNIC, c.c_str());
    }
    void setLocation(string l) {
        strcpy(location, l.c_str());
    }
        void setHospital(string h) {
        strcpy(hospital, h.c_str());
    }
 
    void setExperience(int e) {
        experience = e;
    }
    void setHourlyCharge(double h) {
        hourly_charge = h;
    }
        string getSpecialization() {
        return specialization;
    }
    void setSpecialization(string s) {
        strcpy(specialization, s.c_str());
    }


    void mainMenu();
    Doctor operator=(Doctor obj) {
        setName(obj.getName());
        setUserName(obj.getUserName());
        setPassword(obj.getPassword());
        setLocation(obj.getLocation());
        setHospital(obj.getHospital());
        setEmail(obj.getEmail());
       setSpecialization(obj.getSpecialization());
        setExperience(obj.getExperience());
        setCNIC(obj.getCNIC());
        setHourlyCharge(obj.getHourlyCharge());
    }

};