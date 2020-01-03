//
// Created by Peter Geras on 10/26/19.
//

#include <iostream>
#include "Node.h"

Node::Node(Employee employee, Node *next) {
    this->employee = employee;
    this->next = next;

}

Linklist::Linklist() {

    first = nullptr;

}

void Linklist::add(Employee employee) {

    Node *node = new Node(employee, first);
    first = node;

    // OR first = new Node(employee, first);

}
