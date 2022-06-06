#pragma once
#include <iostream>
using namespace std;

class Payment {
    double balance;
    public:
    Payment() {
        balance = 3500;
    }
    bool depositMoney(double d) {
        balance += d;
        return 1;
    }
    bool withDraw(double d) {
        balance -= d;
        return 1;
    }
    double getBalance() {
        return balance;
    }
    Payment operator=(Payment obj) {
        balance = obj.getBalance();
        return *this;
    }

};