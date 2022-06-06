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
#include "Appointment.h"
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
            cout << "\t\t\t3. Patient" << endl
                 << endl;
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
                    while (admin_option != 8)
                    {

                        cout << "\t\t\tWelcome, " << userName << "!" << endl;
                        cout << endl;
                        cout << "\t\t\t1. View all doctors data" << endl;

                        cout << "\t\t\t2. Delete a doctor from the system" << endl;
                        cout << "\t\t\t3. View all patient's data" << endl;
                        cout << "\t\t\t4. Edit a Doctor's location" << endl;
                        cout << "\t\t\t5. Edit  a Doctor's hospital" << endl;
                        cout << "\t\t\t6. Edit a Doctor's Hourly Charge: " << endl;
                        cout << "\t\t\t7. Edit a Doctor's Experience: " << endl;
                        cout << "\t\t\t8. Logout" << endl;
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
                        else if (admin_option == 8)
                        {
                            break;
                        }
                        else if (admin_option == 4)
                        {
                            clearScreen();
                            cout << endl;
                            cout << "\t\t\tEnter the CNIC of the doctor you wish to edit the location of." << endl
                                 << endl;
                            cout << "\t\t\tCNIC: ";
                            string cnic;
                            cin >> cnic;
                            while (!existsCNIC(cnic))
                            {
                                cout << "\t\t\tThis CNIC does not exist, try a different one: ";
                                cin >> cnic;
                            }
                            string location;
                            cout << "\t\t\tEnter the new location: ";
                            cin >> location;
                            a.editDoctorLocation(cnic, location);
                            cout << "\t\t\tLocation sucessfully updated." << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 5)
                        {
                            clearScreen();
                            cout << endl;
                            cout << "\t\t\tEnter the CNIC of the doctor you wish to edit the hospital of." << endl
                                 << endl;
                            cout << "\t\t\tCNIC: ";
                            string cnic;
                            cin >> cnic;
                            while (!existsCNIC(cnic))
                            {
                                cout << "\t\t\tThis CNIC does not exist, try a different one: ";
                                cin >> cnic;
                            }
                            string hospital;
                            cout << "\t\t\tEnter the new hospital: ";
                            cin >> hospital;
                            a.editDoctorHospital(cnic, hospital);
                            cout << "\t\t\tHospital sucessfully updated." << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 6)
                        {
                            clearScreen();
                            cout << endl;
                            cout << "\t\t\tEnter the CNIC of the doctor you wish to edit the hourly charge of." << endl
                                 << endl;
                            cout << "\t\t\tCNIC: ";
                            string cnic;
                            cin >> cnic;
                            while (!existsCNIC(cnic))
                            {
                                cout << "\t\t\tThis CNIC does not exist, try a different one: ";
                                cin >> cnic;
                            }
                            double h;
                            cout << "\t\t\tEnter the new hourly rate: ";
                            cin >> h;
                            a.editDoctorHourlyCharge(cnic, h);
                            cout << "\t\t\tHourly rate sucessfully updated." << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 7)
                        {
                            clearScreen();
                            cout << endl;
                            cout << "\t\t\tEnter the CNIC of the doctor you wish to edit the experience of." << endl
                                 << endl;
                            cout << "\t\t\tCNIC: ";
                            string cnic;
                            cin >> cnic;
                            while (!existsCNIC(cnic))
                            {
                                cout << "\t\t\tThis CNIC does not exist, try a different one: ";
                                cin >> cnic;
                            }
                            int h;
                            cout << "\t\t\tEnter the new experience: ";
                            cin >> h;
                            a.editDoctorExperience(cnic, h);
                            cout << "\t\t\tExperience sucessfully updated." << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 2)
                        {
                            clearScreen();
                            cout << "\t\t\tEnter the CNIC of the doctor you wish to remove: ";
                            string cnic;
                            cin >> cnic;
                            while (!a.deleteDoctor(cnic))
                            {
                                clearScreen();
                                cout << "\t\t\tThe CNIC you entered does not exist in the system." << endl;
                                cout << "\t\t\tPlease try another one: ";
                                cin >> cnic;
                            }
                            // add option to go back
                            cout << "\t\t\tDoctor successfully removed from the system." << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 1)
                        {
                            clearScreen();
                            a.viewAllDoctors();
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
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
                    string userName;
                    string password;
                    while (!validate)
                    {

                        cout << "\t\t\tUsername: ";
                        cin >> userName;

                        cout << "\t\t\tPassword: ";
                        cin >> password;
                        validate = loginDoctor(userName, password);

                        // cout << "\t\t\tPress 1 to go back: ";
                        // int lol;
                        // cin >> lol;
                    }
                    clearScreen();
                    int doctor_option = 0;
                    ifstream f("doctors.dat", ios::binary);
                    Doctor d;
                    while (f.read((char *)&d, sizeof(d)))
                    {
                        if (d.getUserName() == userName)
                        {
                            break;
                        }
                    }
                    while (doctor_option != 5)
                    {
                        cout << "\t\t\tWelcome, " << d.getName() << endl;
                        cout << endl;
                        cout << "\t\t\t1. Edit Available Times" << endl;
                        cout << "\t\t\t2. Edit Profile" << endl;
                        cout << "\t\t\t3. View scheduled Appointments" << endl;
                        cout << "\t\t\t4. Change appointment details" << endl;
                        cout << "\t\t\t5. Logout" << endl;
                        cout << endl;
                        cout << "\t\t\tChoice: ";
                        cin >> doctor_option;
                        if (doctor_option == 5)
                        {
                            break;
                        }
                        else if (doctor_option == 2)
                        {
                            clearScreen();
                            cout << "\t\t\tEdit Profile" << endl;
                            cout << endl;
                            cout << "\t\t\t1. Edit Hospital" << endl;
                            cout << "\t\t\t2. Edit Location" << endl;
                            cout << "\t\t\t3. Change Hourly rate" << endl;
                            cout << "\t\t\t4. Edit experience" << endl;
                            cout << "\t\t\t5. Change Username" << endl;
                            cout << "\t\t\t6. Change Email" << endl;
                            cout << "\t\t\t7. Reset Password" << endl;
                            cout << "\t\t\t8. Go Back" << endl;
                            int sub_option;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            cin >> sub_option;
                            while (sub_option != 8)
                            {
                                if (sub_option == 8)
                                {
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter the name of your new hospital: ";
                                    string new_hos;
                                    cin >> new_hos;
                                    d.editDoctorHospital(d.getCNIC(), new_hos);
                                    cout << endl;
                                    cout << "\t\t\tHospital Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 2)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new location: ";
                                    string new_loc;
                                    cin >> new_loc;
                                    d.editDoctorLocation(d.getCNIC(), new_loc);
                                    cout << endl;
                                    cout << "\t\t\tLocation Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 3)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new hourly rate: ";
                                    double new_rate;
                                    cin >> new_rate;
                                    d.editDoctorHourlyCharge(d.getCNIC(), new_rate);
                                    cout << endl;
                                    cout << "\t\t\tHourly Charge Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 4)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new experience (in years): ";
                                    int new_exp;
                                    cin >> new_exp;
                                    d.editDoctorExperience(d.getCNIC(), new_exp);
                                    cout << endl;
                                    cout << "\t\t\tExperience Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 5)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new username: ";
                                    string new_usr;
                                    cin >> new_usr;
                                    d.editDoctorUsername(d.getCNIC(), new_usr);
                                    cout << endl;
                                    cout << "\t\t\tUsername Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 6)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new email: ";
                                    string new_em;
                                    cin >> new_em;
                                    while (!emailCheck(new_em))
                                    {
                                        cout << "\t\t\tPlease enter a valid email: ";
                                        cin >> new_em;
                                    }
                                    d.editDoctorEmail(d.getCNIC(), new_em);
                                    cout << endl;
                                    cout << "\t\t\tEmail Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 7)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new password: ";
                                    string new_pass;
                                    cin >> new_pass;
                                    while (!PasswordCheck(new_pass))
                                    {
                                        cout << "\t\t\tPlease enter a valid Password: ";
                                        cin >> new_pass;
                                    }
                                    d.editDoctorPass(d.getCNIC(), new_pass);
                                    cout << endl;
                                    cout << "\t\t\tPassword Successfully updated!" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                            }
                        }
                        else if (doctor_option == 1)
                        {
                            int sub_option;

                            clearScreen();
                            cout << "\t\t\tEdit Available Times" << endl;
                            cout << endl;
                            cout << "\t\t\t1. Add Availability" << endl;
                            cout << "\t\t\t2. Edit Availability" << endl;
                            cout << "\t\t\t3. Delete Availability" << endl;
                            cout << "\t\t\t4. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            cin >> sub_option;
                            while (sub_option != 4)
                            {
                                if (sub_option == 4)
                                {
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    int year, day, month, hour;
                                    clearScreen();
                                    cout << "\t\t\tAdd Availability" << endl;
                                    cout << endl;
                                    cout << "\t\t\tYear: ";
                                    cin >> year;
                                    cout << "\t\t\tMonth: ";
                                    cin >> month;
                                    cout << "\t\t\tDay: ";
                                    cin >> day;
                                    cout << "\t\t\tHour: ";
                                    cin >> hour;

                                    if (d.addAvilability(d.getCNIC(), year, month, day, hour))
                                    {
                                        cout << "\t\t\tAdded Availability Successfully!" << endl;
                                    }
                                    else
                                    {
                                        cout << "\t\t\tAvailable time mismatch" << endl;
                                    }
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back" << endl;
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                }
                            }
                        }
                        else if (doctor_option == 3)
                        {
                            clearScreen();
                            d.viewAllAvailableTime();
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the doctors panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
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
                    string username;
                    string password;

                    while (!validate)

                    {

                        cout << "\t\t\tUsername: ";
                        cin >> username;
                        cout << "\t\t\tPassword: ";
                        cin >> password;
                        validate = loginPatient(username, password);
                    }
                    clearScreen();
                    int patient_option;
                    ifstream f("patients.dat", ios::binary);
                    Patient p;
                    while (f.read((char *)&p, sizeof(p)))
                    {
                        if (p.getUserName() == username)
                        {
                            break;
                        }
                    }
                    f.close();

                    while (patient_option != 6)
                    {
                        cout << "\t\t\tWelcome, " << p.getName() << endl
                             << endl;
                        cout << "\t\t\t1. Edit Profile" << endl;
                        cout << "\t\t\t2. Reset Password" << endl;
                        cout << "\t\t\t3. Appointments" << endl;
                        cout << "\t\t\t4. Recharge Account" << endl;
                        cout << "\t\t\t5. Search Doctors" << endl;
                        cout << "\t\t\t6. Logout" << endl;
                        cout << endl;
                        cout << "\t\t\tChoice: ";
                        cin >> patient_option;
                        if (patient_option == 6)
                        {
                            break;
                        }
                        else if (patient_option == 5)
                        {
                            clearScreen();
                            cout << "\t\t\tHow would you like to look for your doctor?" << endl
                                 << endl;
                            cout << "\t\t\t1. By Speciality" << endl;
                            cout << "\t\t\t2. By Hospital" << endl;
                            cout << "\t\t\t3. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            int sub_option;
                            cin >> sub_option;
                            while (sub_option != 3)
                            {
                                if (sub_option == 3)
                                {
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    clearScreen();
                                    cout << "\t\t\tSearching for Doctors" << endl
                                         << endl;
                                    cout << "\t\t\tSpeciality: ";
                                    string speciality;
                                    cin >> speciality;
                                    cout << endl;
                                    Doctor doc;
                                    cout << "\t\t\tSearch results: " << endl
                                         << endl;
                                    searchDoctorsBySpecialization(speciality);
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 2)
                                {
                                    clearScreen();
                                    cout << "\t\t\tSearching for Doctors" << endl
                                         << endl;
                                    cout << "\t\t\tHospital: ";
                                    string hospital;
                                    cin >> hospital;
                                    Doctor doc;
                                    cout << endl;
                                    cout << "\t\t\tSearch results: " << endl
                                         << endl;
                                    searchDoctorsByHospital(hospital);
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                clearScreen();
                            }
                        }
                        else if (patient_option == 3)
                        {
                            clearScreen();
                            cout << "\t\t\tAppointments" << endl
                                 << endl;
                            cout << "\t\t\t1. Book an Appointment" << endl;
                            cout << "\t\t\t2. My Appointments" << endl;
                            cout << "\t\t\t3. Cancel an Appointment" << endl;
                            cout << "\t\t\t4. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            int sub_option;
                            cin >> sub_option;
                            while (sub_option != 4)
                            {
                                if (sub_option == 4)
                                {
                                    break;
                                }
                                else if(sub_option == 2) {
                                    clearScreen();
                                    cout << "\t\t\tMy Appointments: " << endl;
                                    cout << endl;
                                    viewPatientAppointments(p);
                                    cout << endl;
                                    cout << "Press enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    clearScreen();
                                    cout << "\t\t\tBook Appointment" << endl
                                         << endl;
                                    cout << "\t\t\tHow would you like to look for your doctor?" << endl
                                         << endl;
                                    cout << "\t\t\t1. By Speciality" << endl;
                                    cout << "\t\t\t2. By Hospital" << endl;
                                    cout << "\t\t\t3. Go Back" << endl;
                                    cout << endl;
                                    cout << "\t\t\tChoice: ";
                                    int sub_sub;
                                    cin >> sub_sub;
                                    while (sub_sub != 3)
                                    {
                                        if (sub_sub == 3)
                                        {
                                            break;
                                        }
                                        else if (sub_sub == 1)
                                        {
                                            clearScreen();
                                            cout << "\t\t\tSearching for Doctors" << endl
                                                 << endl;
                                            cout << "\t\t\tSpeciality: ";
                                            string speciality;
                                            cin >> speciality;
                                            cout << endl;

                                            cout << "\t\t\tSearch results: " << endl
                                                 << endl;
                                            Doctor *docs = searchDoctorsBySpecialization(speciality);
                                            cout << endl;
                                            cout << "\t\t\tSelect: ";
                                            int doc_choice;
                                            cin >> doc_choice;
                                            clearScreen();
                                            cout << "\t\t\tAppointment Type" << endl << endl;
                                            cout << "\t\t\t1. In person" << endl; 
                                            cout << "\t\t\t2. Online" << endl;
                                            int type;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> type;
                                            clearScreen();
                                            cout << "\t\t\tDate of Booking" << endl << endl;
                                            cout << "\t\t\tYear: ";
                                            int year;
                                            int month;
                                            int day;
                                            int hour;
                                            cin >> year;
                                            cout << "\t\t\tMonth: ";
                                            cin >> month;
                                            cout << "\t\t\tDay: ";
                                            cin >> day;
                                            cout << "\t\t\tHour: ";
                                            cin >> hour;
                                            Date date(year, month, day, hour);
                                            bool created = createAppointment(p, docs[doc_choice - 1], type, date);
                                            if (created) {
                                                cout << endl;
                                                cout << "\t\t\tAppointment successfully created. Please be sure to be on time for your appointment." << endl;
                                            }
                                            cout << "\t\t\tPress enter to go back...";
                                            cin.get();
                                            cin.get();
                                            clearScreen();
                                            break;
                                        }
                                        else if(sub_sub == 2) {
                                          clearScreen();
                                            cout << "\t\t\tSearching for Doctors" << endl
                                                 << endl;
                                            cout << "\t\t\tHospital: ";
                                            string hospital;
                                            cin >> hospital;
                                            cout << endl;

                                            cout << "\t\t\tSearch results: " << endl
                                                 << endl;
                                            Doctor *docs = searchDoctorsByHospital(hospital);
                                            cout << endl;
                                            cout << "\t\t\tSelect: ";
                                            int doc_choice;
                                            cin >> doc_choice;
                                            clearScreen();
                                            cout << "\t\t\tAppointment Type" << endl << endl;
                                            cout << "\t\t\t1. In person" << endl; 
                                            cout << "\t\t\t2. Online" << endl;
                                            int type;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> type;
                                            clearScreen();
                                            cout << "\t\t\tDate of Booking" << endl << endl;
                                            cout << "\t\t\tYear: ";
                                            int year;
                                            int month;
                                            int day;
                                            int hour;
                                            cin >> year;
                                            cout << "\t\t\tMonth: ";
                                            cin >> month;
                                            cout << "\t\t\tDay: ";
                                            cin >> day;
                                            cout << "\t\t\tHour: ";
                                            cin >> hour;
                                            Date date(year, month, day, hour);
                                            bool created = createAppointment(p, docs[doc_choice - 1], type, date);
                                            if (created) {
                                                cout << endl;
                                                cout << "\t\t\tAppointment successfully created. Please be sure to be on time for your appointment." << endl;
                                            }
                                            cout << "\t\t\tPress enter to go back...";
                                            cin.get();
                                            cin.get();
                                            clearScreen();
                                            break;
                                        } 
                                    }
                                }
                            }
                        }
                        else if (patient_option == 1)
                        {
                            clearScreen();
                            cout << "\t\t\tEdit Profile" << endl
                                 << endl;
                            cout << "\t\t\t1. Change Name" << endl;
                            cout << "\t\t\t2. Change Username" << endl;
                            cout << "\t\t\t3. Change Email" << endl;
                            cout << "\t\t\t4. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            int sub_option;
                            cin >> sub_option;

                            while (sub_option != 4)
                            {
                                if (sub_option == 4)
                                {
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new name: ";
                                    string new_name;
                                    cin >> new_name;
                                    p.editName(p.getCNIC(), new_name);
                                    cout << endl;
                                    cout << "\t\t\tName Successfully Updated" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 2)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new Username: ";
                                    string new_name;
                                    cin >> new_name;
                                    p.editUsername(p.getCNIC(), new_name);
                                    cout << endl;
                                    cout << "\t\t\tUsername Successfully Updated" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 3)
                                {
                                    clearScreen();
                                    cout << "\t\t\tEnter your new Email: ";
                                    string new_email;
                                    cin >> new_email;
                                    while (!emailCheck(new_email))
                                    {
                                        cout << "\t\t\tPlease enter a valid email: ";
                                        cin >> new_email;
                                    }
                                    p.editEmail(p.getCNIC(), new_email);
                                    cout << endl;
                                    cout << "\t\t\tEmail Successfully Updated" << endl;
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                            }
                        }
                        else if (patient_option == 2)
                        {
                            clearScreen();
                            cout << "\t\t\tEnter your new password: ";
                            string new_pass;
                            cin >> new_pass;
                            while (!PasswordCheck(new_pass))
                            {
                                cout << "\t\t\tPlease enter a valid Password: ";
                                cin >> new_pass;
                            }
                            p.resetPassword(p.getCNIC(), new_pass);
                            cout << endl;
                            cout << "\t\t\tPassword Successfully reset!" << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                            break;
                        }
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
    bool loginDoctor(string userName, string password)
    {

        Doctor p;

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
    bool loginPatient(string username, string password)
    {

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
    Doctor *searchDoctorsBySpecialization(string s)
    {
        int number = 0;
        Doctor *arr = new Doctor[number + 1];
        Doctor doc;
        ifstream doctors("doctors.dat", ios::binary);
        int i = 1;
        while (doctors.read((char *)&doc, sizeof(doc)))
        {
            if (s == doc.getSpecialization())
            {
                arr[number++] = doc;
                cout << "\t\t\tDoctor " << i << ": " << endl
                     << endl;
                cout << "\t\t\tName: " << doc.getName() << endl;
                cout << "\t\t\tHospital: " << doc.getHospital() << endl;
                cout << "\t\t\tLocation: " << doc.getLocation() << endl;
                cout << "\t\t\tHourly rate: " << doc.getHourlyCharge() << endl;
                cout << "\t\t\tSpecialization: " << doc.getSpecialization() << endl;
                cout << endl;
                i++;
            }
        }
        return arr;
    }

    Doctor *searchDoctorsByHospital(string s)
    {
        int number = 0;
        Doctor *arr = new Doctor[number + 1];
        Doctor doc;
        ifstream doctors("doctors.dat", ios::binary);
        int i = 1;
        while (doctors.read((char *)&doc, sizeof(doc)))
        {
            if (s == doc.getHospital())
            {
                arr[number++] = doc;
                cout << "\t\t\tDoctor " << i << ": " << endl
                     << endl;
                cout << "\t\t\tName: " << doc.getName() << endl;
                cout << "\t\t\tHospital: " << doc.getHospital() << endl;
                cout << "\t\t\tLocation: " << doc.getLocation() << endl;
                cout << "\t\t\tHourly rate: " << doc.getHourlyCharge() << endl;
                cout << "\t\t\tSpecialization: " << doc.getSpecialization() << endl;
                cout << endl;
                i++;
            }
        }
        return arr;
    }

    bool createAppointment(Patient p, Doctor d, int type, Date booking_date) {
        Appointment a(d, p, booking_date, type);
        a.setAppointmentStatus("Pending");
        ofstream appointments("appointments.dat", ios::binary | ios::app);
        appointments.write((char*)&a, sizeof(a));
        return 1;
    }
    void viewPatientAppointments(Patient p) {
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        while (appointments.read((char*)&app, sizeof(app))) {
            if (app.getPatient().getUserName() == p.getUserName()) {
                cout << "\t\t\tAppointment " << i << endl << endl;
                cout << "\t\t\tDoctor name: " << app.getDoctor().getName() << endl;
                cout << "\t\t\tDoctor Speciality: " << app.getDoctor().getSpecialization() << endl;
                if (app.getAppointmentType() == 1) {
                    cout << "\t\t\tType: In Person" << endl; 
                }
                else {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
                << app.getDate().getHour() << endl;
                cout << "\t\t\tDate of Booking: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
                << app.getDate().getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
            }
        }
    }
};