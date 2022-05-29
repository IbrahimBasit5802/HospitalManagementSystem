#pragma once
#include <iostream>
using namespace std;


class Date{
    int year;
    int month;
    int day;
    int hour;
    public:
    Date(int a = 0, int b = 0, int c= 0, int d = 0) {
        year = a;
        month = b;
        day = c;
        hour = d;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    int getHour() {
        return hour;
    }
    void setYear(int y) {
        year = y;
    }
    void setMonth(int m) {
        month = m;
    }
    void setDay(int d) {
        day = d;
    }
    void setHour(int h) {
        hour = h;
    }

};