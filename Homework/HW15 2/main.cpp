#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Node.h"



Linklist getEmployeeList(){
    using namespace std;

    ifstream infile1("../Employee_info.txt");
    ifstream infile2("../hours.txt");

    int idNumber;
    int hours;
    double payRate;
    string employeeName;

    Linklist linkedList;

    while(infile1 >> idNumber >> payRate){
        getline(infile1,employeeName);
        Employee employee(idNumber, payRate, employeeName);
        linkedList.add(employee);

    }



    while (infile2 >> idNumber >> hours){
        auto n = linkedList.first;
        while(n != nullptr){
            if (idNumber == n->employee.idNumber){
                n->employee.hours += hours;
                break;
            }
            n = n->next;
        }

//        while(n != nullptr && idNumber != n->employee.idNumber) {
//            n = n->next;
//        }
//        if (n != nullptr) {
//            n->employee.hours += hours;
//        } else {
//            // error out here
//        }

    }

    return linkedList;
}


int main() {
    using namespace std;


    auto e = getEmployeeList();

    vector<Employee> employees;

    auto n = e.first;

    while (n != nullptr){
       employees.push_back(n->employee);
        n = n->next;
    }

    sort(employees.begin(), employees.end(), greater <>());


    cout << "*********Payroll Information********" << endl;


    for (int i = 0; i < employees.size(); ++i) {

        cout << employees[i].employeeName << ", $" << employees[i].totalPay() << endl;

    }


    cout << "*********End payroll**************" << endl;

    return 0;
}