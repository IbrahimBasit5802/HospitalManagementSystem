#pragma once
#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include <fstream>
#include <cstring>
using namespace std;
class Oladoc
{
public:
    void menu()
    {
        cout << "\t\t\t\tWelcome to Oladoc!" << endl;
        cout << "\t\t\t1. Admin" << endl;
        cout << "\t\t\t2. Doctor" << endl;
        cout << "\t\t\t3. Patient" << endl << endl;
        int user_type;
        cout << "\t\t\tChoice: ";
        cin >> user_type;
        cout << endl;
        int panel_choice;
        bool validate;
        if (user_type == 2)
        {
            cout << "\t\t\tWelcome Doctor!" << endl
                 << endl;
            cout << "\t\t\t1. Login" << endl;
            cout << "\t\t\t2. Sign Up" << endl
                 << endl;
            cout << "\t\t\tChoice: ";
            cin >> panel_choice;
            cout << endl;
            if (panel_choice == 2)
            {
                cout << endl
                     << endl;
                registerDoctor();
            }
            else if (panel_choice == 1)
            {

                validate = false;
                while (!validate)
                {
                    validate = loginDoctor();
                }
            }
        }
        else if (user_type == 3)
        {
            cout << "\t\t\tWelcome Patient!" << endl;
            cout << "\t\t\t1. Login" << endl;
            cout << "\t\t\t2. Sign Up" << endl
                 << endl;
            cout << "\t\t\tChoice: ";
            cin >> panel_choice;
            cout << endl;
            if (panel_choice == 2)
            {
                cout << endl
                     << endl;
                registerPatient();
            }
            else if (panel_choice == 1)
            {
                cout << endl
                     << endl;

                int y;
                cout << "\t\t\t1. Login using Email" << endl;
                cout << "\t\t\t2. Login using CNIC" << endl;
                cout << endl;
                cout << "\t\t\tChoice: ";

                cin >> y;
                validate = false;
                while (!validate)
                {
                    validate = loginPatient(y);
                }
            }
        }
    }
    bool loginAdmin(string userName, string Password);
    bool loginDoctor()
    {
        string CNIC;
        string password;
        Doctor p;
        cout << "\t\t\tCNIC: ";
        cin >> CNIC;

        cout << "\t\t\tPassword: ";
        cin >> password;
        ifstream file("doctors.dat", ios::binary);
        while (file.read((char *)&p, sizeof(p)))
        {
            if (p.getCNIC() == CNIC)
            {
                if (p.getPassword() == password)
                {
                    cout << endl;
                    cout << "\t\t\tLogin Successful!";

                    return 1;
                }
            }
        }
        cout << endl
             << "\t\t\tIncorrect Credentials, please try again" << endl;
        file.close();
        return 0;
    }
    bool loginPatient(int x)
    {
        string email;
        string cnic;
        string password;

        if (x == 1)
        {
            cout << "\t\t\tEmail: ";
            cin >> email;
            cout << "\t\t\tPassword: ";
            cin >> password;
            ifstream file("patients.dat", ios::binary);
            Patient p;
            while (file.read((char *)&p, sizeof(p)))
            {
                if (p.getEmail() == email)
                {
                    if (p.getPassword() == password)
                    {
                        cout << endl;
                        cout << "\t\t\tLogin Successful!";

                        return 1;
                    }
                }
            }
            cout << endl
                 << "\t\t\tIncorrect Credentials, please try again" << endl;
            file.close();
        }
        else if (x == 2)
        {
            cout << "\t\t\tCNIC: ";
            cin >> cnic;
            cout << "\t\t\tPassword: ";
            cin >> password;
            ifstream file("patients.dat", ios::binary);
            Patient p;
            while (file.read((char *)&p, sizeof(p)))
            {
                if (p.getCNIC() == cnic)
                {
                    if (p.getPassword() == password)
                    {
                        cout << endl;
                        cout << "\t\t\tLogin Successful!";

                        return 1;
                    }
                }
            }
            cout << endl
                 << "\t\t\tIncorrect Credentials, please try again" << endl;
            file.close();
        }
        return 0;
    }
    bool registerPatient()
    {
        string name;
        string username;
        string password;
        string cnic;
        string email;
        cout << "\t\t\tName: ";
        cin >> name;
        cout << "\t\t\tUserName: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        while (!PasswordCheck(password))
        {
            cout << "\t\t\tPlease enter a valid Password: ";
            cin >> password;
        }
        cout << "\t\t\tCNIC: ";
        cin >> cnic;
        // add cnic check
        while (!cnicCheck(cnic)) {
            cout << "\t\t\tPlease enter a valid CNIC: ";
            cin >> cnic;
        }
        cout << "\t\t\tEmail: ";
        cin >> email;
        // add email check
        while (!emailCheck(email)) {
            cout << "\t\t\tPlease enter a valid Email: ";
            cin >> email;
        }
        Patient p(name, username, password, cnic, email);
        ofstream patients("patients.dat", ios::binary | ios::app);
        patients.write((char *)&p, sizeof(p));
        patients.close();
        return 1;
    }
    bool logoutAdmin();
    bool logoutDoctor();
    bool logoutPatient();
    bool registerDoctor()
    {
        string name;
        string username;
        string password;
        string cnic;
        string email;
        string hospital_name;
        string hospital_location;
        string specialization;
        int experience;
        double hourly_charge;
        cout << "\t\t\tName: ";
        getline(cin, name);
        cout << "\t\t\tUserName: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        getline(cin, password);
        while (!PasswordCheck(password))
        {
            cout << "\t\t\tPlease enter a valid Password: ";
            getline(cin, password);
        }
        cout << "\t\t\tCNIC: ";
        cin >> cnic;
        // add cnic check
        while (!cnicCheck(cnic)) {
            cout << "\t\t\tPlease enter a valid CNIC: ";
            cin >> cnic;
        }
        cout << "\t\t\tEmail: ";
        cin >> email;
        // add email check
        while (!emailCheck(email)) {
            cout << "\t\t\tPlease enter a valid Email: ";
            cin >> email;
        }
        cout << "\t\t\tName of the Hospital you work at: ";
        getline(cin, hospital_name);
        cout << "\t\t\tLocation of the hospital: ";
        getline(cin, hospital_location);
        cout << "\t\t\tYour Specialization: ";
        getline(cin, specialization);
        cout << "\t\t\tYour experience (in years): ";
        cin >> experience;
        cout << "\t\t\tYour Hourly Rate: ";
        cin >> hourly_charge;
        Doctor d(name, username, password, cnic, email, hospital_name, hospital_location, specialization, experience, hourly_charge);
        ofstream doctors("doctors.dat", ios::binary | ios::app);
        doctors.write((char *)&d, sizeof(d));
        doctors.close();
    }
    bool PasswordCheck(string p)
    {
        int len = 0;
        while (p[len] != 0)
        {
            len++;
        }
        if (len < 8)
        {
            return 0;
        }
        bool special_characters = false;
        bool upper_case = false;
        bool lower_case = false;
        bool digit = false;
        for (int i = 0; i < len; i++)
        {
            if ((p[i] >= 32 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126))
            {
                special_characters = true;
            }
            if (p[i] >= 65 && p[i] <= 90)
            {
                upper_case = true;
            }
            if (p[i] >= 97 && p[i] <= 122)
            {
                lower_case = true;
            }
            if (p[i] >= 48 && p[i] <= 57)
            {
                digit = true;
            }
        }
        if (special_characters && upper_case && lower_case && digit)
        {
            return 1;
        }
        return 0;
    }
    bool cnicCheck(string c) {
        int len = 0;
        while (c[len] != 0) {
            len++;
        }
        if (len != 13) {
            return 0;
        }
        for (int i = 0; i < len; i++) {
            if (c[i] < 48 || c[i] > 57) {
                return 0;
            }
        }
        return 1;
    }
    bool emailCheck(string e) {
        bool at = false;
        int len = 0;
        while (e[len] != 0) {
            len++;
        }
        for (int i = 0; i < len; i++) {
            if (e[i] == 64) {
                at = true;
            }

        }

        if (at) {
            return 1;
        }
        return 0;
    }
};