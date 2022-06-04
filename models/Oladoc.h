#pragma once
#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include "Admin.h"
#include "Dermatologist.h"
#include "Orthopedic.h"
#include "Gynecologist.h"
#include <fstream>
#include "Oncologist.h"
#include <stdlib.h>
#include <cstring>
using namespace std;
class Oladoc
{
public:
    void menu()
    {
        while (true)
        {
            clearScreen();
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
            clearScreen();
            if (user_type == 1)
            {
                cout << "\t\t\tWelcome Admin!" << endl
                     << endl;
                cout << "\t\t\t1. Login" << endl
                     << endl;
                cout << "\t\t\tChoice: ";
                cin >> panel_choice;
                clearScreen();
                if (panel_choice == 1)
                {
                    string userName;
                    string pass;
                    validate = false;
                    while (!validate)
                    {
                        cout << "\t\t\tUsername: ";
                        cin >> userName;
                        cout << "\t\t\tPassword: ";
                        cin >> pass;
                        validate = loginAdmin(userName, pass);
                        // cout << "\t\t\tPress 1 to go back: ";
                        // int lol;
                        // cin >> lol;
                    }
                    clearScreen();
                    int admin_option = 0;

                    cout << "\t\t\tLogin Successful" << endl;
                    cout << endl;
                    while (admin_option != 4)
                    {

                        cout << "\t\t\tWelcome, " << userName << "!" << endl;
                        cout << endl;
                        cout << "\t\t\t1. Add a doctor to the system" << endl;
                        cout << "\t\t\t2. Delete a doctor from the system" << endl;
                        cout << "\t\t\t3. View all patient's data" << endl;
                        cout << "\t\t\t4. Logout" << endl;
                        cout << endl;
                        Admin a(userName, pass);
                        cout << "\t\t\tChoice: ";
                        cin >> admin_option;
                        if (admin_option == 3)
                        {
                            clearScreen();
                            a.viewAllPatientData();
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        if (admin_option == 4)
                        {
                            break;
                        }
                    }
                }
            }
            else if (user_type == 2)
            {
                cout << "\t\t\tWelcome Doctor!" << endl
                     << endl;
                cout << "\t\t\t1. Login" << endl;
                cout << "\t\t\t2. Sign Up" << endl
                     << endl;
                cout << "\t\t\tChoice: ";
                cin >> panel_choice;
                clearScreen();
                cout << endl;
                if (panel_choice == 2)
                {

                    registerDoctor();
                }
                else if (panel_choice == 1)
                {
                    ifstream file("doctors.dat", ios::binary);
                    if (file)
                    {
                        validate = false;
                    }

                    else
                    {
                        validate = true;
                        cout << "\t\t\tThere are no doctors registered in the system." << endl;
                        cout << "\t\t\tPress enter to go back to the main menu." << endl;
                        cin.get();
                        cin.get();
                    }
                    file.close();

                    while (!validate)
                    {
                        validate = loginDoctor();
                        // cout << "\t\t\tPress 1 to go back: ";
                        // int lol;
                        // cin >> lol;
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
                clearScreen();
                cout << endl;
                if (panel_choice == 2)
                {

                    registerPatient();
                }
                else if (panel_choice == 1)
                {

                    ifstream file("patients.dat", ios::binary);
                    if (file)
                    {
                        validate = false;
                    }

                    else
                    {
                        validate = true;
                        cout << "\t\t\tThere are no patients registered in the system." << endl;
                        cout << "\t\t\tPress enter to go back.....";
                        cin.get();
                        cin.get();
                    }
                    file.close();
                    while (!validate)
                    {
                        validate = loginPatient();
                    }
                }
            }
        }
    }
    bool loginAdmin(string userName, string pass)
    {

        Admin a(userName, pass);
        ifstream file("admin.dat", ios::binary);
        while (file.read((char *)&a, sizeof(a)))
        {
            if (a.getUserName() == userName)
            {
                if (a.getPassword() == pass)
                {
                    cout << endl;
                    return 1;
                }
            }
        }
        clearScreen();
        cout << "\t\t\tIncorrect Credentials, please try again" << endl;
        file.close();
        return 0;
    }
    bool loginDoctor()
    {
        string userName;
        string password;
        Doctor p;
        cout << "\t\t\tUsername: ";
        cin >> userName;

        cout << "\t\t\tPassword: ";
        cin >> password;
        ifstream file("doctors.dat", ios::binary);
        while (file.read((char *)&p, sizeof(p)))
        {
            if (p.getUserName() == userName)
            {
                if (p.getPassword() == password)
                {
                    cout << endl;
                    cout << "\t\t\tLogin Successful!" << endl;
                    clearScreen();
                    return 1;
                }
            }
        }
        clearScreen();
        cout << "\t\t\tIncorrect Credentials, please try again" << endl;
        file.close();
        return 0;
    }
    bool loginPatient()
    {
        string username;
        string password;

        cout << "\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        ifstream file("patients.dat", ios::binary);
        Patient p;
        while (file.read((char *)&p, sizeof(p)))
        {
            if (p.getUserName() == username)
            {
                if (p.getPassword() == password)
                {
                    cout << endl;
                    cout << "\t\t\tLogin Successful!" << endl;
                    clearScreen();
                    return 1;
                }
            }
        }
        clearScreen();
        cout << "\t\t\tIncorrect Credentials, please try again" << endl;

        file.close();

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
        cout << "\t\t\tUsername: ";
        cin >> username;
        while (!checkUsername(username))
        {
            cout << "Please enter a valid username, make sure it doesn't have any spaces: ";
            cin >> username;
        }
        while (existsUserName(username))
        {
            cout << "\t\t\tThis username has already been taken, use a different one: ";
            cin >> username;
        }
        cout << "\t\t\tEmail: ";
        cin >> email;
        // add email check
        while (!emailCheck(email))
        {
            cout << "\t\t\tPlease enter a valid Email: ";
            cin >> email;
        }
        while (existsEmail(email))
        {
            cout << "\t\t\tThis email already exists, try a different one: ";
            cin >> email;
        }
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
        while (!cnicCheck(cnic))
        {
            cout << "\t\t\tPlease enter a valid CNIC: ";
            cin >> cnic;
        }
        while (existsCNIC(cnic))
        {
            cout << "\t\t\tThis CNIC already exists, try a different one: ";
            cin >> cnic;
        }

        Patient p(name, username, password, cnic, email);
        ofstream patients("patients.dat", ios::binary | ios::app);
        patients.write((char *)&p, sizeof(p));
        patients.close();
        clearScreen();
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
        cin >> name;
        cout << "\t\t\tUsername: ";
        cin >> username;
        while (!checkUsername(username))
        {
            cout << "Please enter a valid username, make sure it doesn't have any spaces: ";
            cin >> username;
        }
        while (existsUserName(username))
        {
            cout << "\t\t\tThis username has already been taken, use a different one: ";
            cin >> username;
        }
        cout << "\t\t\tEmail: ";
        cin >> email;
        // add email check
        while (!emailCheck(email))
        {
            cout << "\t\t\tPlease enter a valid Email: ";
            cin >> email;
        }
        while (existsEmail(email))
        {
            cout << "\t\t\tThis email already exists, try a different one: ";
            cin >> email;
        }
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
        while (!cnicCheck(cnic))
        {
            cout << "\t\t\tPlease enter a valid CNIC: ";
            cin >> cnic;
        }
        while (existsCNIC(cnic))
        {
            cout << "\t\t\tThis CNIC already exists, try a different one: ";
            cin >> cnic;
        }

        cout << "\t\t\tName of the Hospital you work at: ";
        cin >> hospital_name;
        cout << "\t\t\tLocation of the hospital: ";
        cin >> hospital_location;
        cout << "\t\t\tYour Specialization: ";
        cin >> specialization;
        cout << "\t\t\tYour experience (in years): ";
        cin >> experience;
        cout << "\t\t\tYour Hourly Rate: ";
        cin >> hourly_charge;

        Doctor d(name, username, password, cnic, email, hospital_name, hospital_location, specialization, experience, hourly_charge);
        ofstream doctors("doctors.dat", ios::binary | ios::app);
        doctors.write((char *)&d, sizeof(d));
        doctors.close();

        // else if(specialization == "Dermatologist") {
        //     Dermatologist d(name, username, password, cnic, email, hospital_name, hospital_location, experience, hourly_charge, specialization);
        //     ofstream doctors("doctors.dat", ios::binary | ios::app);
        //     doctors.write((char *)&d, sizeof(d) + sizeof(Dermatologist));
        //     doctors.close();
        // }
        // else if (specialization == "Orthopedic") {
        //     Orthopedic d(name, username, password, cnic, email, hospital_name, hospital_location, experience, hourly_charge, specialization);
        //     ofstream doctors("doctors.dat", ios::binary | ios::app);
        //     doctors.write((char *)&d, sizeof(d) + sizeof(Orthopedic));
        //     doctors.close();
        // }
        // else if (specialization == "Gynecologist") {
        //     Gynecologist d(name, username, password, cnic, email, hospital_name, hospital_location, experience, hourly_charge, specialization);
        //     ofstream doctors("doctors.dat", ios::binary | ios::app);
        //     doctors.write((char *)&d, sizeof(d) + sizeof(Gynecologist));
        //     doctors.close();
        // }

        clearScreen();
        return 1;
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
    bool cnicCheck(string c)
    {
        int len = 0;
        while (c[len] != 0)
        {
            len++;
        }
        if (len != 13)
        {
            return 0;
        }
        for (int i = 0; i < len; i++)
        {
            if (c[i] < 48 || c[i] > 57)
            {
                return 0;
            }
        }
        return 1;
    }
    bool emailCheck(string e)
    {
        bool at = false;
        int len = 0;
        while (e[len] != 0)
        {
            len++;
        }
        for (int i = 0; i < len; i++)
        {
            if (e[i] == 64)
            {
                at = true;
            }
        }

        if (at)
        {
            return 1;
        }
        return 0;
    }
    void clearScreen()
    {
#ifdef _WIN32
        system("CLS");
#endif
#ifdef __APPLE__
        system("clear");
#endif
    }
    bool existsCNIC(string cnic)
    {
        ifstream doctors("doctors.dat", ios::binary);
        Doctor d;
        while (doctors.read((char *)&d, sizeof(d)))
        {
            if (cnic == d.getCNIC())
            {
                doctors.close();
                return 1;
            }
        }
        doctors.close();
        ifstream patients("patients.dat", ios::binary);
        Patient p;
        while (patients.read((char *)&p, sizeof(p)))
        {
            if (cnic == p.getCNIC())
            {
                patients.close();
                return 1;
            }
        }
        patients.close();
        return 0;
    }
    bool existsEmail(string email)
    {
        ifstream doctors("doctors.dat", ios::binary);
        Doctor d;
        while (doctors.read((char *)&d, sizeof(d)))
        {
            if (email == d.getEmail())
            {
                doctors.close();
                return 1;
            }
        }
        doctors.close();
        ifstream patients("patients.dat", ios::binary);
        Patient p;
        while (patients.read((char *)&p, sizeof(p)))
        {
            if (email == p.getEmail())
            {
                patients.close();
                return 1;
            }
        }
        patients.close();
        return 0;
    }
    bool existsUserName(string username)
    {
        ifstream doctors("doctors.dat", ios::binary);
        Doctor d;
        while (doctors.read((char *)&d, sizeof(d)))
        {
            if (username == d.getUserName())
            {
                doctors.close();
                return 1;
            }
        }
        doctors.close();
        ifstream patients("patients.dat", ios::binary);
        Patient p;
        while (patients.read((char *)&p, sizeof(p)))
        {
            if (username == p.getUserName())
            {
                patients.close();
                return 1;
            }
        }
        patients.close();
        return 0;
    }
    bool checkUsername(string username)
    {
        for (int i = 0; i < username.length(); i++)
        {
            if (username[i] == ' ')
            {
                return 0;
            }
        }
        return 1;
    }
};