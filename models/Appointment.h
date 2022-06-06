#pragma once

#include <iostream>
using namespace std;
#include "Patient.h"
#include "Doctor.h"
#include "Date.h"
class Appointment {
    Patient p;
    Doctor doc;
    Date date;
    Date booking_date;
    int appointment_type;
    char appointment_status[100];
    public:
    Appointment() {
        
    }
    Appointment(Doctor doctor, Patient patient, Date d, int type) {
        doc = doctor;
        p = patient;
        date = d;
        booking_date = d;
        appointment_type = type;
        string status = "Pending";
        strcpy(appointment_status, status.c_str());
    }

    Patient getPatient() {
        return p;
    }
    Doctor getDoctor() {
        return doc;
    }
    Date getDate() {
        return date;
    }
    void setPatient(Patient patient) {
        p = patient;
    }
    void setDoctor(Doctor doctor) {
        doc = doctor;
    }
    void setDate(Date obj) {
        date = obj;
    }
    int getAppointmentType() {
        return appointment_type;
    }
    void setAppointmentType(int a) {
        appointment_type = a;
    }
    char * getAppointmentStatus() {
        return appointment_status;
    }
    void setAppointmentStatus(string a) {
        strcpy(appointment_status, a.c_str());
    }
};