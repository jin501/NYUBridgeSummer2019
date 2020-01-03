//
// Created by Peter Geras on 10/26/19.
//

#ifndef HW15_NODE_H
#define HW15_NODE_H

#include <iostream>
#include "Employee.h"

using namespace std;



class Node {


public:

    Employee employee;
    Node *next;

    Node(Employee employee, Node *next);

};

class Linklist {
public:
    Node *first;

    Linklist();

    void add(Employee employee);
};




#endif //HW15_NODE_H
