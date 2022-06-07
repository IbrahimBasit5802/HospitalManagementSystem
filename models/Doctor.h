#pragma once
#include <iostream>
#include "User.h"
#include "Feedback.h"
#include "Payment.h"
#include <fstream>
#include "Date.h"
#include<string.h>
using namespace std;

class Doctor : public User {
    protected:

    char location[100];
    char hospital[100];
    int no_feedbacks;
    double hourly_charge;
    char specialization[100];
    int experience;
    char CNIC[100];
    char email[100];
    int rating;
    Payment * payments;
    int no_payments;
    public:
    Date *available_times;
    int no_times;
    FeedBack feedbacks[50];

    
    Doctor(string n = "", string u = "", string p = "", string c = "", string em = "", string h = "", string l = "", string s = "", int e = 0, double h_c = 0.0) : User(n, u, p) {
        strcpy(this->CNIC, c.c_str());
        strcpy(this->hospital, h.c_str());
        strcpy(this->location, l.c_str());
        strcpy(this->specialization, s.c_str());
        experience = e;
        hourly_charge = h_c;
        strcpy(this->email, em.c_str());
        no_times = 0;
        no_feedbacks = 0;
        available_times = new Date[10];
 

    }
    string getCNIC() {
        return CNIC;
    }

    string getEmail() {
        return email;
    }
    char* getLocation() {
        return location;
    }
    string getHospital() {
        return hospital;
    }
    void addReview(string r, double rat) {
  
        FeedBack f(r, rat);
   
        feedbacks[no_feedbacks++] = f;

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

    int getNoOfFeedBacks() {
        return no_feedbacks;
    }
    void setNoOfFeedbacks(int n) {
        no_feedbacks = n;
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
    bool addAvilability(string cnic, int y, int m, int d, int h) {

        Date doc(y, m, d, h);


        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor ds;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (ds.getCNIC() == cnic)
            {
                cout << "ok" << endl;
                ds.available_times[no_times++] = doc;
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        f.close();
        return 1;
        


    }

    double getAverageRating() {
        double avg = 0;
        for (int i = 0; i < getNoOfFeedBacks(); i++) {
            avg += feedbacks[i].getRating();
        }
        return avg / getNoOfFeedBacks();
    }

    int getNo_Times() {
        return no_times;
    }

        bool editDoctorHospital(string c, string h)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setHospital(h);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    bool editDoctorLocation(string c, string l)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setLocation(l);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }

    bool editDoctorHourlyCharge(string c, double h)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setHourlyCharge(h);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    bool editDoctorExperience(string c, int e)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setExperience(e);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    bool editDoctorUsername(string c, string u)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setUserName(u);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    bool editDoctorEmail(string c, string e)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setEmail(e);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    bool editDoctorPass(string c, string p)
    {
        bool found = false;
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == c)
            {
                found = true;
                d.setPassword(p);
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }
        return found;
    }
    void viewAllAvailableTime() {
        cout << "\t\t\tAvailable Times: " << endl << endl;
        int x = 1;
        for (int i = 0; i < no_times; i++) {
            cout << "ok" << endl;
            cout << "\t\t\t" << x << ". " << available_times[i].getDay() << "/" << available_times[i].getMonth() << "/" << available_times[i].getYear() << " ";
            cout << "| " << available_times[i].getHour() << endl;
            cout << endl;
            x++;
        }
    }

};