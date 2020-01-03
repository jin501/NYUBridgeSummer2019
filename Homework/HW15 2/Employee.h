//
// Created by Peter Geras on 10/26/19.
//


#ifndef HW15_EMPLOYEE_H
#define HW15_EMPLOYEE_H

#include <iostream>

using namespace std;


class Employee {

private:
    double payRate;

public:
    int hours;
    int idNumber;
    string employeeName;


    Employee() = default;

    Employee(int idNumber, double payRate, string employeeName);

    double totalPay() const ;

    friend bool operator > (const Employee& e1, const Employee& e2);
    friend bool operator < (const Employee& e1, const Employee& e2);


};


#endif //HW15_EMPLOYEE_H
