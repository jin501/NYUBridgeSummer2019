//
// Created by Peter Geras on 10/26/19.
//
#include <iostream>
#include "Employee.h"


Employee::Employee(int idNumber, double payRate, string employeeName) {
    this->idNumber = idNumber;
    this->payRate = payRate;
    this->employeeName = employeeName;
    this->hours = 0;
}

double Employee::totalPay() const {

    return hours * payRate;

}

bool operator>(const Employee &e1, const Employee &e2) {
    return e1.totalPay() > e2.totalPay();
}

bool operator<(const Employee &e1, const Employee &e2) {

    return e1.totalPay() < e2.totalPay();

}











