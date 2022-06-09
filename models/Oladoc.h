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
    // shows menu and distinct views for all three types of users
    void menu()
    {
        while (true)
        {
            clearScreen();
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\tWelcome to Oladoc!" << endl << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\tYour health buddy" << endl << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
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
                draw();
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
                    draw();
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
                    cout << "\t\t\tLogin Successful" << endl;

                    clearScreen();
                    int admin_option = 0;

                    while (admin_option != 9)
                    {
                        draw();

                        cout << "\t\t\tWelcome, " << userName << "!" << endl;
                        cout << endl;
                        cout << "\t\t\t1. View all doctors data" << endl;

                        cout << "\t\t\t2. Delete a doctor from the system" << endl;
                        cout << "\t\t\t3. View all patient's data" << endl;
                        cout << "\t\t\t4. Edit a Doctor's location" << endl;
                        cout << "\t\t\t5. Edit  a Doctor's hospital" << endl;
                        cout << "\t\t\t6. Edit a Doctor's Hourly Charge: " << endl;
                        cout << "\t\t\t7. Edit a Doctor's Experience: " << endl;
                        cout << "\t\t\t8. View all Appointments" << endl;
                        cout << "\t\t\t9. Logout" << endl;
                        cout << endl;
                        Admin a(userName, pass);
                        cout << "\t\t\tChoice: ";
                        cin >> admin_option;
                        if (admin_option == 3)
                        {
                            clearScreen();
                            draw();
                            a.viewAllPatientData();
                            cout << endl;
                            cout << "\t\t\tPress enter to go back to the admin panel...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 9)
                        {
                            break;
                        }
                        else if (admin_option == 8)
                        {
                            clearScreen();
                            draw();
                            cout << "\t\t\tAppointments" << endl
                                 << endl;
                            viewAllAppointments();
                            cout << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (admin_option == 4)
                        {
                            clearScreen();
                            draw();
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
                            draw();
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
                            draw();
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
                            draw();
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
                            draw();
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
                            draw();
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
                draw();
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
                    draw();

                    registerDoctor();
                }
                else if (panel_choice == 1)
                {
                    ifstream file("doctors.dat", ios::binary);
                    draw();
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
                    f.close();
                    while (doctor_option != 6)
                    {
                        draw();
                        cout << "\t\t\tWelcome, " << d.getName() << endl;
                        cout << endl;
                        cout << "\t\t\t1. Edit Available Times" << endl;
                        cout << "\t\t\t2. Edit Profile" << endl;
                        cout << "\t\t\t3. View scheduled Appointments" << endl;
                        cout << "\t\t\t4. Change appointment details" << endl;
                        cout << "\t\t\t5. My reviews" << endl;
                        cout << "\t\t\t6. Logout" << endl;
                        cout << endl;
                        cout << "\t\t\tChoice: ";
                        cin >> doctor_option;
                        if (doctor_option == 6)
                        {
                            break;
                        }
                        else if(doctor_option == 5) {
                            clearScreen();
                            draw();
                            cout << "\t\t\tMy reviews and ratings" << endl << endl;
                            for (int i = 0; i < d.getNoOfFeedBacks(); i++) {
                                cout << "\t\t\tFeedback " << i + 1 << ": " << endl << endl;
                                cout << "\t\t\tReview: " << d.feedbacks[i].getReview() << endl;
                                cout << "\t\t\tRating: " << d.feedbacks[i].getRating() << endl;
                                cout << endl;

                            } 
                            cout << endl;
                            cout << "\t\t\tYour overall rating: " << d.getAverageRating() << endl;
                            cout << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        
                        }
                        else if (doctor_option == 3)
                        {
                            clearScreen();
                            draw();
                            cout << "\t\t\tMy Scheduled Appointments" << endl
                                 << endl;
                            viewScheduledAppointments(d);
                            cout << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        
                        else if (doctor_option == 4)
                        {
                            clearScreen();
                            draw();
                            cout << "\t\t\tAppointment Manager" << endl
                                 << endl;
                            cout << "\t\t\t1. Complete an Appointment" << endl;
                            cout << "\t\t\t2. Cancel an appointment" << endl;
                            cout << "\t\t\t3. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            int ch;
                            cin >> ch;
                            while (ch != 3)
                            {
                                if (ch == 3)
                                {
                                    break;
                                }
                                else if (ch == 1)
                                {
                                    clearScreen();
                                    draw();
                                    completeAppointmentDoctor(d);

                                    clearScreen();
                                    cout << "The appointment has been completed" << endl
                                         << endl;
                                    cout << "\t\t\tPress enter to go back";
                                    cin.get();
                                    clearScreen();
                                    break;
                                }

                                else if(ch == 2) {
                                    clearScreen();
                                    draw();
                                    cout << "\t\t\tAppointment Cancellation" << endl
                                         << endl;
                                    Doctor temp = deleteAppointmentDoctor(d);
                                    cout << endl;
                                    cout << "\t\t\tAppointment successfully cancelled" << endl;
                                    cout << endl
                                         << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;                             
                                }
                            }
                        }
                        else if (doctor_option == 2)
                        {
                            clearScreen();
                            draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                            draw();
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
                                    draw();
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
                                    break;
                                }
                            }
                        }
                        else if (doctor_option == 3)
                        {
                            clearScreen();
                            draw();
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
                draw();
                cout << "\t\t\tWelcome Patient!" << endl << endl;
                cout << "\t\t\t1. Login" << endl;
                cout << "\t\t\t2. Sign Up" << endl
                     << endl;
                cout << "\t\t\tChoice: ";
                cin >> panel_choice;
                clearScreen();
                cout << endl;
                if (panel_choice == 2)
                {
                    draw();

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
                        draw();
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
                        draw();

                        cout << "\t\t\tUsername: ";
                        cin >> username;
                        cout << "\t\t\tPassword: ";
                        cin >> password;
                        validate = loginPatient(username, password);
                    }
                    clearScreen();
                    draw();
                    int patient_option = 0;
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

                    while (patient_option != 7)
                    {
                        clearScreen();
                        draw();
                        cout << "\t\t\tWelcome, " << p.getName() << endl
                             << endl;
                        cout << "\t\t\t1. Edit Profile" << endl;

                        cout << "\t\t\t2. Reset Password" << endl;
                        cout << "\t\t\t3. Appointments" << endl;
                        cout << "\t\t\t4. Recharge Account" << endl;
                        cout << "\t\t\t5. Search Doctors" << endl;
                        cout << "\t\t\t6. Check Balance" << endl;
                        cout << "\t\t\t7. Logout" << endl;
                        cout << endl;
                        cout << "\t\t\tChoice: ";
                        cin >> patient_option;
                        if (patient_option == 7)
                        {
                            break;
                        }
                        else if (patient_option == 6)
                        {
                            clearScreen();
                            draw();
                            cout << "\t\t\tBalance Inquiry" << endl
                                 << endl;
                            cout << "\t\t\tYour Balance is: " << p.account.getBalance() << endl
                                 << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (patient_option == 4)
                        {
                            clearScreen();
                            draw();
                            cout << "\t\t\tRecharge Account" << endl;
                            cout << endl;
                            cout << "\t\t\tAmount to add: ";
                            int amount;
                            cin >> amount;
                            string file = "patients.dat";
                            fstream f(file.c_str(), ios::in | ios::binary | ios::out);
                            Patient d;
                            while (f.read((char *)&d, sizeof(d)))
                            {
                                if (d.getCNIC() == p.getCNIC())
                                {
                                    d.account.depositMoney(amount);
                                    p = d;
                                    int cur = f.tellg();
                                    int size = sizeof(d);
                                    f.seekg(cur - size, ios::beg);
                                    f.write((char *)&d, sizeof(d));
                                    f.close();
                                }
                            }
                            clearScreen();
                            draw();
                            cout << "\t\t\tAccount successfully Recharged" << endl
                                 << endl;
                            cout << "\t\t\tPress enter to go back...";
                            cin.get();
                            cin.get();
                            clearScreen();
                        }
                        else if (patient_option == 5)
                        {
                            clearScreen();
                            draw();
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
                                    draw();
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
                                    draw();
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
                            draw();
                            cout << "\t\t\tAppointments" << endl
                                 << endl;
                            cout << "\t\t\t1. Book an Appointment" << endl;
                            cout << "\t\t\t2. My Appointments" << endl;
                            cout << "\t\t\t3. Cancel an Appointment" << endl;
                            cout << "\t\t\t4. Complete Appointment" << endl;
                            cout << "\t\t\t5. Go Back" << endl;
                            cout << endl;
                            cout << "\t\t\tChoice: ";
                            int sub_option;
                            cin >> sub_option;
                            while (sub_option != 5)
                            {
                                if (sub_option == 5)
                                {
                                    break;
                                }
                                else if(sub_option == 4) {
                                    clearScreen();
                                    draw();
                                    completeAppointment(p);

                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 3)
                                {
                                    clearScreen();
                                    draw();
                                    cout << "\t\t\tAppointment Cancellation" << endl
                                         << endl;
                                    Patient temp = deleteAppointment(p);
                                    p = temp;
                                    cout << endl;
                                    cout << "\t\t\tAppointment successfully cancelled" << endl;
                                    cout << endl
                                         << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 2)
                                {
                                    clearScreen();
                                    draw();
                                    cout << "\t\t\tMy Appointments: " << endl;
                                    cout << endl;
                                    viewPatientAppointments(p);
                                    cout << endl;
                                    cout << "\t\t\tPress enter to go back...";
                                    cin.get();
                                    cin.get();
                                    clearScreen();
                                    break;
                                }
                                else if (sub_option == 1)
                                {
                                    clearScreen();
                                    draw();
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
                                    if(sub_sub == 3) {
                                        break;
                                    }
                                    while (sub_sub != 3)
                                    {
                                        if (sub_sub == 3)
                                        {
                                            break;
                                        }
                                        else if (sub_sub == 1)
                                        {
                                            clearScreen();
                                            draw();
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
                                            draw();
                                            cout << "\t\t\tAppointment Type" << endl
                                                 << endl;
                                            cout << "\t\t\t1. In person" << endl;
                                            cout << "\t\t\t2. Online" << endl;
                                            int type;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> type;
                                            clearScreen();
                                            draw();
                                            cout << "\t\t\tDate of Booking" << endl
                                                 << endl;
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
                                            clearScreen();
                                            draw();
                                            Date appointment_date(year, month, day, hour);
                                            bool created = createAppointment(p, docs[doc_choice - 1], type, date, appointment_date);

                                            string file = "patients.dat";
                                            fstream f(file.c_str(), ios::in | ios::binary | ios::out);
                                            Patient d;
                                            while (f.read((char *)&d, sizeof(d)))
                                            {
                                                if (d.getCNIC() == p.getCNIC())
                                                {
                                                    if (type == 2)
                                                    {
                                                        d.account.withDraw(0.7 * (docs[doc_choice - 1].getHourlyCharge()));
                                                    }
                                                    else
                                                    {
                                                        d.account.withDraw(docs[doc_choice - 1].getHourlyCharge());
                                                    }
                                                    p = d;
                                                    int cur = f.tellg();
                                                    int size = sizeof(d);
                                                    f.seekg(cur - size, ios::beg);
                                                    f.write((char *)&d, sizeof(d));
                                                    f.close();
                                                }
                                            }
                                            clearScreen();
                                            draw();
                                            cout << "\t\t\tPayment Method" << endl
                                                 << endl;
                                            cout << "\t\t\t1. JazzCash" << endl;
                                            cout << "\t\t\t2. Easypaisa" << endl;
                                            cout << "\t\t\t3. UnionPay" << endl;
                                            cout << "\t\t\t4. Bank Transfer" << endl;
                                            int payment_option;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> payment_option;
                                            clearScreen();
                                            draw();
                                            if (created)
                                            {
                                                cout << endl;
                                                cout << "\t\t\tAppointment successfully created. Your account has been charged. Please be sure to be on time for your appointment." << endl;
                                            }
                                            cout << "\t\t\tPress enter to go back...";
                                            cin.get();
                                            cin.get();
                                            clearScreen();
                                            break;
                                        }
                                        else if (sub_sub == 2)
                                        {
                                            clearScreen();
                                            draw();
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
                                            draw();
                                            cout << "\t\t\tAppointment Type" << endl
                                                 << endl;
                                            cout << "\t\t\t1. In person" << endl;
                                            cout << "\t\t\t2. Online" << endl;
                                            int type;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> type;
                                            clearScreen();
                                            draw();
                                            cout << "\t\t\tDate of Booking" << endl
                                                 << endl;
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
                                            clearScreen();
                                            draw();
                                            Date appointment_date = displayDoctorTimings(docs[doc_choice  - 1]);
                                            bool created = createAppointment(p, docs[doc_choice - 1], type, date, appointment_date);

                                            string file = "patients.dat";
                                            fstream f(file.c_str(), ios::in | ios::binary | ios::out);
                                            Patient d;
                                            while (f.read((char *)&d, sizeof(d)))
                                            {
                                                if (d.getCNIC() == p.getCNIC())
                                                {
                                                    if (type == 2)
                                                    {
                                                        d.account.withDraw(0.7 * (docs[doc_choice - 1].getHourlyCharge()));
                                                    }
                                                    else
                                                    {
                                                        d.account.withDraw(docs[doc_choice - 1].getHourlyCharge());
                                                    }
                                                    p = d;
                                                    int cur = f.tellg();
                                                    int size = sizeof(d);
                                                    f.seekg(cur - size, ios::beg);
                                                    f.write((char *)&d, sizeof(d));
                                                    f.close();
                                                }
                                            }
                                            clearScreen();
                                            draw();
                                            cout << "\t\t\tPayment Method" << endl
                                                 << endl;
                                            cout << "\t\t\t1. JazzCash" << endl;
                                            cout << "\t\t\t2. Easypaisa" << endl;
                                            cout << "\t\t\t3. UnionPay" << endl;
                                            cout << "\t\t\t4. Bank Transfer" << endl;
                                            int payment_option;
                                            cout << endl;
                                            cout << "\t\t\tChoice: ";
                                            cin >> payment_option;
                                            clearScreen();
                                            draw();
                                            if (created)
                                            {
                                                cout << endl;
                                                cout << "\t\t\tAppointment successfully created. Your account has been charged. Please be sure to be on time for your appointment." << endl;
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
                            draw();
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
                                    draw();
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
                                    draw();
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
                                    draw();
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
                            draw();
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
    // logs in admin
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
    // login Doctor through files
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
    // Login Patient
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
    // registers patients and writs to patients.dat file
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

    // Shows appropriate menu and registers doctor
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

  

        clearScreen();
        return 1;
    }
    // Input validation for all passwords
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
    // checks if cnic is valid
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
    // checks if email is valid
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
    // check if cnic exists
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
    // checks if email exists
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
    // Checks if usernames exists
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
    // Input validation check for username
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

    // Searching doctor by specialization using doctor array
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
                cout << "\t\t\tRating: " << doc.getAverageRating() << endl;
                i++;
            }
        }
        return arr;
    }

    // Displays all available times of doctor

    Date displayDoctorTimings(Doctor d) {
        Date *timings;
        int num = 0;
        timings = new Date[num + 1];
        cout << "\t\t\tTimings: " << endl << endl;
        int x = 1;
        for(int i = 0; i < d.getNo_Times(); i++) {
            cout << x << ". " << d.available_times[i].getYear() << "/" << d.available_times[i].getMonth() << "/" << d.available_times[i].getDay() << "/" << " | " << d.available_times[i].getHour() << endl;
            timings[num++] = d.available_times[i];
        }

        int choice;
        cout << endl;
        cout << "\t\t\tChoice: ";
        cin >> choice;
        return timings[choice - 1];


    }

    // Searches Doctors by Hspital and returns a Doctor array

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
                cout << "\t\t\tRating: " << doc.getAverageRating() << endl;
                cout << endl;
                i++;
            }
        }
        return arr;
    }


    // Creates an appointment for patient

    bool createAppointment(Patient p, Doctor d, int type, Date booking_date, Date app_date)
    {
        Appointment a(d, p, app_date, type, booking_date);
        a.setAppointmentStatus("Pending");
        ofstream appointments("appointments.dat", ios::binary | ios::app);
        // p.account.withDraw(d.getHourlyCharge());

        appointments.write((char *)&a, sizeof(a));
        appointments.close();
        return 1;
    }
    // View logged in patients appoinments
    void viewPatientAppointments(Patient p)
    {
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        while (appointments.read((char *)&app, sizeof(app)))
        {
            if (app.getPatient().getUserName() == p.getUserName())
            {
                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tDoctor name: " << app.getDoctor().getName() << endl;
                cout << "\t\t\tDoctor Speciality: " << app.getDoctor().getSpecialization() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
                     << app.getDate().getHour() << endl;
                cout << "\t\t\tDate of Booking: " << app.getBookingDate().getYear() << "/" << app.getBookingDate().getMonth() << "/" << app.getBookingDate().getDay() << " | "
                     << app.getDate().getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
            }
        }
        appointments.close();
    }
    void draw() {
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\tWelcome to Oladoc!" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\tYour health buddy" << endl << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    }
    // function to cancelAppointment from doctor's side
    Doctor deleteAppointmentDoctor(Doctor d) {
        cout << "\t\t\tYour Appointments: " << endl
             << endl;
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        int num = 0;
        Appointment *apps = new Appointment[num + 1];
        Patient pa;
        Doctor doc;
        Date booking_date;
        Date date;
        while (appointments.read((char *)&app, sizeof(app)))
        {
            pa = app.getPatient();
            doc = app.getDoctor();
            booking_date = app.getDate();
            date = app.getDate();
            if (doc.getUserName() == d.getUserName())
            {
                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tPatient name: " << pa.getName() << endl;
                cout << "\t\t\tPatient Email: " << pa.getEmail() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << " | "
                     << date.getHour() << endl;
                cout << "\t\t\tDate of Booking: " << booking_date.getYear() << "/" << booking_date.getMonth() << "/" << booking_date.getDay() << " | "
                     << booking_date.getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
                apps[num++] = app;
            }

        }
        cout << endl;
        cout << "\t\t\tSelect the appointment to cancel: ";
        int choice;
        cin >> choice;
        Appointment a;
        appointments.close();
        Date de = apps[choice - 1].getDate();
        Date des;
        ifstream file("appointments.dat", ios::binary);
        ofstream temp("temp.dat", ios::binary | ios::app);
        Doctor temp_doc;
        while (file.read((char *)&a, sizeof(a)))
        {
            des = a.getDate();
            temp_doc = a.getDoctor();

            if (temp_doc.getUserName() == d.getUserName())
            {
                if (de.getDay() != des.getDay() || de.getMonth() != des.getMonth() || de.getHour() != des.getHour())
                {

                    temp.write((char *)&a, sizeof(a));
                }
            }
        }
        file.close();
        temp.close();
        remove("appointments.dat");
        rename("temp.dat", "appointments.dat");
        clearScreen();
        return d;
    }
    // function to cancelAppointment from patient side
    Patient deleteAppointment(Patient p)
    {
        cout << "\t\t\tYour Appointments: " << endl
             << endl;
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        int num = 0;
        Appointment *apps = new Appointment[num + 1];
        Patient pa;
        Doctor d;
        Date booking_date;
        Date date;
        while (appointments.read((char *)&app, sizeof(app)))
        {

                                        pa = app.getPatient();
            d = app.getDoctor();
            booking_date = app.getDate();
            date = app.getDate();

            if (pa.getUserName() == p.getUserName())
            {

                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tDoctor name: " << d.getName() << endl;
                cout << "\t\t\tDoctor Speciality: " << d.getSpecialization() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << " | "
                     << date.getHour() << endl;
                cout << "\t\t\tDate of Booking: " << booking_date.getYear() << "/" << booking_date.getMonth() << "/" << booking_date.getDay() << " | "
                     << booking_date.getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
                apps[num++] = app;
            }
        }

        cout << endl;
        cout << "\t\t\tSelect the appointment to cancel: ";
        int choice;
        cin >> choice;
        Appointment a;
        Date de = apps[choice - 1].getDate();
        Patient patient = apps[choice - 1].getPatient(); 
        Date des;
        int xD;
        appointments.close();
        ofstream temp("temp.dat", ios::binary | ios::app);
        ifstream file("appointments.dat", ios::binary);
        Patient g;
        while (file.read((char *)&a, sizeof(a)))
        {

            // cout << patient.getUserName() << " " << p.getUserName() << endl;
            // system("pause");
            // cin >> xD;
            g = a.getPatient();
            if (patient.getUserName() == g.getUserName())
            {


                des = a.getDate();
                if (de.getDay() != des.getDay() || de.getMonth() != des.getMonth() || de.getHour() != des.getHour())
                {
                    // cout << "ok test" << endl;
                    // int x;
                    // cin >> x;

                    temp.write((char *)&a, sizeof(a));
                }
            }
        }
        clearScreen();
        cout << "\t\t\tEnter Date of Cancellation" << endl
             << endl;
        int year;
        int month;
        int day;
        cout << "\t\t\tYear: ";
        cin >> year;
        cout << "\t\t\tMonth: ";
        cin >> month;
        cout << "\t\t\tDay: ";
        cin >> day;
        Date cancellation_date(year, month, day);
        booking_date = apps[choice - 1].getBookingDate();

        string file_name = "patients.dat";
        fstream f(file_name.c_str(), ios::in | ios::binary | ios::out);
        Patient pat;
        // refund
        while (f.read((char *)&d, sizeof(d)))
        {
            if (d.getCNIC() == p.getCNIC())
            {
                if (apps[choice - 1].getAppointmentType() == 1)
                {
                    if (cancellation_date.getDay() - booking_date.getDay() == 0)
                    {
                        pat.account.depositMoney(d.getHourlyCharge());
                    }
                    else if (cancellation_date.getDay() - booking_date.getDay() == 1)
                    {
                        pat.account.depositMoney(0.6 * (d.getHourlyCharge()));
                    }
                    else if (cancellation_date.getDay() - booking_date.getDay() == 2)
                    {
                        pat.account.depositMoney(0.3 * (d.getHourlyCharge()));
                    }
                }
                else
                {
                    if (cancellation_date.getDay() - booking_date.getDay() == 0)
                    {
                        p.account.depositMoney(0.7 * (d.getHourlyCharge()));
                    }
                    else if (cancellation_date.getDay() - booking_date.getDay() == 1)
                    {
                        p.account.depositMoney(0.6 * (0.7 * (d.getHourlyCharge())));
                    }
                    else if (cancellation_date.getDay() - booking_date.getDay() == 2)
                    {
                        p.account.depositMoney(0.3 * (0.7 * (d.getHourlyCharge())));
                    }
                }
                int cur = f.tellg();
                int size = sizeof(d);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&d, sizeof(d));
                f.close();
            }
        }

        file.close();
        temp.close();
        remove("appointments.dat");
        rename("temp.dat", "appointments.dat");

        return pat;
    }
    // Function to complete appointment from patient side
    void completeAppointmentDoctor(Doctor d) {
        cout << "\t\t\tYour Appointments: " << endl
             << endl;
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        int num = 0;
        Appointment *apps = new Appointment[num + 1];
        Doctor pa;
        Patient p;
        Date booking_date;
        Date date;
        while (appointments.read((char *)&app, sizeof(app)))
        {

                                        pa = app.getDoctor();
            p = app.getPatient();
            booking_date = app.getDate();
            date = app.getDate();

            if (d.getUserName() == pa.getUserName())
            {

                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tPatient name: " << p.getName() << endl;
                cout << "\t\t\tpatient Email: " << p.getEmail() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << " | "
                     << date.getHour() << endl;
                cout << "\t\t\tDate of Booking: " << booking_date.getYear() << "/" << booking_date.getMonth() << "/" << booking_date.getDay() << " | "
                     << booking_date.getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
                apps[num++] = app;
            }
        }
        appointments.close();
        cout << "\t\t\tSelect the appointment to complete: ";
        int selection;
        cin >> selection;
        
        cout << endl;
        ofstream tempfile("temp.dat", ios::binary | ios::app);
        ifstream appoint("appointments.dat", ios::binary);
        Appointment x;
        Patient g;
        Date des;
        Date de = apps[selection - 1].getDate();
        while (appoint.read((char *)&x, sizeof(x)))
        {

            // cout << patient.getUserName() << " " << p.getUserName() << endl;
            // system("pause");
            // cin >> xD;
            g = apps[selection - 1].getPatient();
            Patient temppatient = x.getPatient();
            if (temppatient.getUserName() == g.getUserName())
            {


                des = x.getDate();
                if (de.getDay() != des.getDay() || de.getMonth() != des.getMonth() || de.getHour() != des.getHour())
                {
                    // cout << "ok test" << endl;
                    // int x;
                    // cin >> x;

                    tempfile.write((char *)&x, sizeof(x));
                }
            }
        }
        tempfile.close();
        appoint.close();
        remove("appointments.dat");
        rename("temp.dat", "appointments.dat");
        cin.get();
        cin.get();

        
    }
    // Function to complete appointment from patient side
    void completeAppointment(Patient p) {
        cout << "\t\t\tYour Appointments: " << endl
             << endl;
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;
        int num = 0;
        Appointment *apps = new Appointment[num + 1];
        Patient pa;
        Doctor d;
        Date booking_date;
        Date date;
        while (appointments.read((char *)&app, sizeof(app)))
        {

                                        pa = app.getPatient();
            d = app.getDoctor();
            booking_date = app.getDate();
            date = app.getDate();

            if (pa.getUserName() == p.getUserName())
            {

                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tDoctor name: " << d.getName() << endl;
                cout << "\t\t\tDoctor Speciality: " << d.getSpecialization() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << " | "
                     << date.getHour() << endl;
                cout << "\t\t\tDate of Booking: " << booking_date.getYear() << "/" << booking_date.getMonth() << "/" << booking_date.getDay() << " | "
                     << booking_date.getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
                apps[num++] = app;
            }
        }
        appointments.close();
        cout << "\t\t\tSelect the appointment to complete: ";
        int selection;
        cin >> selection;
        clearScreen();
        cout << "\t\t\tPlease give a review" << endl << endl;
        cout << "\t\t\tYour review: ";
        string review;
        cin >> review;
        cout << "\t\t\tRate your doctor (from 0 to 5): ";
        double rate;
        cin >> rate;

        Doctor temp = apps[selection - 1].getDoctor();
        string file = "doctors.dat";
        fstream f(file.c_str(), ios::in | ios::binary | ios::out);
        Doctor dag;
        while (f.read((char *)&dag, sizeof(dag)))
        {
            if (dag.getUserName() == temp.getUserName())
            {
                dag.addReview(review, rate);
                int cur = f.tellg();
                int size = sizeof(dag);
                f.seekg(cur - size, ios::beg);
                f.write((char *)&dag, sizeof(dag));
                f.close();
            }
        }
        f.close();
        cout << endl;
        cout << "\t\t\tReview Recorded." << endl;
        cout << endl;
        ofstream tempfile("temp.dat", ios::binary | ios::app);
        ifstream appoint("appointments.dat", ios::binary);
        Appointment x;
        Patient g;
        Date des;
        Date de = apps[selection - 1].getDate();
        while (appoint.read((char *)&x, sizeof(x)))
        {

            // cout << patient.getUserName() << " " << p.getUserName() << endl;
            // system("pause");
            // cin >> xD;
            g = apps[selection - 1].getPatient();
            Patient temppatient = x.getPatient();
            if (temppatient.getUserName() == g.getUserName())
            {


                des = x.getDate();
                if (de.getDay() != des.getDay() || de.getMonth() != des.getMonth() || de.getHour() != des.getHour())
                {
                    // cout << "ok test" << endl;
                    // int x;
                    // cin >> x;

                    tempfile.write((char *)&x, sizeof(x));
                }
            }
        }
        cout << endl;
        tempfile.close();
        appoint.close();
        remove("appointments.dat");
        rename("temp.dat", "appointments.dat");
        cout << "\t\t\tPress enter to go back...";
        cin.get();
        cin.get();

        
    }

    Appointment *viewScheduledAppointments(Doctor d)
    {
        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int num = 0;
        Appointment *apps = new Appointment[num + 1];
        int i = 1;
        while (appointments.read((char *)&app, sizeof(app)))
        {
            if (app.getDoctor().getUserName() == d.getUserName())
            {
                cout << "\t\t\tAppointment " << i << endl
                     << endl;
                cout << "\t\t\tPatient name: " << app.getPatient().getName() << endl;
                cout << "\t\t\tPatient Email: " << app.getPatient().getEmail() << endl;
                if (app.getAppointmentType() == 1)
                {
                    cout << "\t\t\tType: In Person" << endl;
                }
                else
                {
                    cout << "\t\t\tType: Online" << endl;
                }
                cout << "\t\t\tDate of Appointment: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
                     << app.getDate().getHour() << endl;
                cout << "\t\t\tDate of Booking: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
                     << app.getDate().getHour() << endl;
                cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
                cout << endl;
                i++;
                apps[num++] = app;
            }
        }
        appointments.close();
        return apps;
    }

    void viewAllAppointments()
    {

        ifstream appointments("appointments.dat", ios::binary);
        Appointment app;
        int i = 1;

        cout << "\t\t\tAppointment " << i << endl
             << endl;
        cout << "\t\t\tPatient name: " << app.getPatient().getName() << endl;
        cout << "\t\t\tPatient Email: " << app.getPatient().getEmail() << endl;
        cout << "\t\t\tDoctor Name: " << app.getDoctor().getName() << endl;
        cout << "\t\t\tDoctor Speciality: " << app.getDoctor().getSpecialization() << endl;

        if (app.getAppointmentType() == 1)
        {
            cout << "\t\t\tType: In Person" << endl;
        }
        else
        {
            cout << "\t\t\tType: Online" << endl;
        }
        cout << "\t\t\tDate of Appointment: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
             << app.getDate().getHour() << endl;
        cout << "\t\t\tDate of Booking: " << app.getDate().getYear() << "/" << app.getDate().getMonth() << "/" << app.getDate().getDay() << " | "
             << app.getDate().getHour() << endl;
        cout << "\t\t\tAppointment Status: " << app.getAppointmentStatus() << endl;
        cout << endl;
        i++;

        appointments.close();
    }
};