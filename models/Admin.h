#pragma once
#include <iostream>
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include <fstream>
using namespace std;

class Admin : public User
{
public:
    Admin(string a, string b) : User(a, a, b)
    {
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
        strcpy(Name, n.c_str());
    }
    void setUserName(string u)
    {
        strcpy(userName, u.c_str());
    }
    void setPassword(string p)
    {
        strcpy(Password, p.c_str());
    }

    void viewAllPatientData()
    {

        ifstream patients("patients.dat", ios::binary);
        if (!patients)
        {
            cout << "\t\t\tThere are no patients registered." << endl;
            cout << "\t\t\tPress enter to go back...";
            cin.get();
            cin.get();
            return;
        }
        Patient p;
        int i = 1;
        while (patients.read((char *)&p, sizeof(p)))
        {
            cout << "\t\t\tPatient " << i << ": " << endl
                 << endl;
            cout << "\t\t\tName: " << p.getName() << endl;
            cout << "\t\t\tUsername: " << p.getUserName() << endl;
            cout << "\t\t\tCNIC: " << p.getCNIC() << endl;
            cout << "\t\t\tEmail: " << p.getEmail() << endl;

            cout << endl;
            i++;
        }
        patients.close();
    }
    bool deleteDoctor(string c)
    {
        bool found = false;
        ifstream f("doctors.dat", ios::binary);
        ofstream temp("temp.dat", ios::binary);
        Doctor d;
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() != c)
            {
                temp.write((char *)&d, sizeof(d));
            }
            else
            {
                found = true;
            }
        }
        if (!found)
        {
            return 0;
        }
        f.close();
        temp.close();
        remove("doctors.dat");
        rename("temp.dat", "doctors.dat");
        return 1;
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

    void viewAllDoctors()
    {
        ifstream doctors("doctors.dat", ios::binary);
        if (!doctors)
        {
            cout << "\t\t\tThere are no doctors registered." << endl;
            cout << "\t\t\tPress enter to go back...";
            cin.get();
            cin.get();
            return;
        }
        Doctor d;
        int i = 1;
        while (doctors.read((char *)&d, sizeof(d)))
        {
            cout << "\t\t\tDoctor " << i << ": " << endl
                 << endl;
            cout << "\t\t\tName: " << d.getName() << endl;
            cout << "\t\t\tUsername: " << d.getUserName() << endl;
            cout << "\t\t\tCNIC: " << d.getCNIC() << endl;
            cout << "\t\t\tEmail: " << d.getEmail() << endl;
            cout << "\t\t\tHospital: " << d.getHospital() << endl;
            cout << "\t\t\tLocation: " << d.getLocation() << endl;
            cout << "\t\t\tHourly Rate: " << d.getHourlyCharge() << endl;
            cout << "\t\t\tExperience: " << d.getExperience() << " years" << endl;
            cout << "\t\t\tSpecialization: " << d.getSpecialization() << endl;
            cout << endl;
            i++;
        }
        doctors.close();
    }
    Admin operator=(Admin obj)
    {
        setName(obj.getName());
        setUserName(obj.getUserName());
        setPassword(obj.getPassword());
    }
};