#pragma once
#include <iostream>
#include "Doctor.h"
#include <fstream>
#include <cstring>
using namespace std;
class Oladoc {
    public:
    void menu() {
        cout << "\t\t\t\tWelcome to Oladoc!" << endl;
        cout << "\t\t\t1. Admin" << endl;
        cout << "\t\t\t2. Doctor" << endl;
        cout << "\t\t\t3. Patient" << endl << endl;
        int user_type;
        cout << "\t\t\tChoice: ";
        cin >> user_type;
        cout << endl;
        if (user_type == 2) {
            cout << "\t\t\tWelcome Doctor!" << endl << endl;
            cout << "\t\t\t1. Login" << endl;
            cout << "\t\t\t2. Sign Up" << endl << endl;
            int panel_choice;
            cout << "\t\t\tChoice: ";
            cin >> panel_choice;
            cout << endl;
            if (panel_choice == 2) {
                cout << endl << endl;
                registerDoctor();

            }
            else if(panel_choice == 1) {
                bool validate = false;
                while (!validate) {
                    validate = loginDoctor();
                }
            }
        }

        


    }
    bool loginAdmin(string userName, string Password);
    bool loginDoctor() {
        string CNIC;
        string password;
        Doctor p;
        cout << "\t\t\tCNIC: ";
        cin >> CNIC;
        cout << "\t\t\tPassword: ";
        cin >> password;
        ifstream file("doctors.dat", ios::binary);
        while (file.read((char*)&p, sizeof(p))) {
            if (p.getCNIC() == CNIC) {
                if (p.getPassword() == password) {
                    cout << endl;
                    cout << "\t\t\tLogin Successful!";
                    return 1;
                }
            }
        }
        cout << endl << "\t\t\tIncorrect Credentials, please try again" << endl;
        return 0;
    }
    bool loginPatient();
    bool logoutAdmin();
    bool logoutDoctor();
    bool logoutPatient();
    bool registerDoctor() {
                string name;
                string username;
                string password;
                string cnic;
                string hospital_name;
                string hospital_location;
                string specialization;
                int experience;
                double hourly_charge;
                cout << "\t\t\tName: ";
                cin >> name;
                cout << "\t\t\tUserName: ";
                cin >> username;
                cout << "\t\t\tPassword: ";
                cin >> password;
                while(!PasswordCheck(password)) {
                    cout << "\t\t\tPlease enter a valid password: " << endl;
                    cin >> password;
                }
                cout << "\t\t\tCNIC: ";
                cin >> cnic;
                // check if file exists
                // add cnic check
                cout << "\t\t\tName of the Hospital you work at: ";
                cin >> hospital_name;
                cout << "\t\t\tLocation of the hospital: ";
                cin >>hospital_location;
                cout << "\t\t\tYour Specialization: ";
                cin >>specialization;
                cout << "\t\t\tYour experience (in years): ";
                cin >> experience;
                cout << "\t\t\tYour Hourly Rate: ";
                cin >> hourly_charge;
                Doctor d(name, username, password, cnic, hospital_name, hospital_location, specialization, experience, hourly_charge);
                ofstream doctors("doctors.dat", ios::binary | ios::app);
                doctors.write((char*)&d, sizeof(d));
                doctors.close();

                
    }
    bool PasswordCheck(string p) {
        int len = 0;
        while (p[len] != 0) {
            len++;
        }
        if (len < 8) {
            return 0;
        }
        bool special_characters = false;
        bool upper_case = false;
        bool lower_case = false;
        bool digit = false;
        for (int i = 0; i < len; i++) {
            if ((p[i] >= 32 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126)) {
                special_characters = true;
            }
            if (p[i] >= 65 && p[i] <= 90) {
                upper_case = true;
            }
            if (p[i] >= 97 && p[i] <= 122) {
                lower_case = true;
            }
            if (p[i] >= 48 && p[i] <= 57) {
                digit = true;
            }
        }
        if (special_characters && upper_case && lower_case && digit) {
            return 1;
        }
        return 0;
    }

};  