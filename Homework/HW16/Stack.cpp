//
// Created by Peter Geras on 11/2/19.
//
#include <iostream>
#include <fstream>
#include "Stack.h"



void Stack::push(char cha) {
    data.push_back(cha);
}

char Stack::pop() {

    if (size() != 0){
        char temp = data[data.size() - 1];
        data.pop_back();
        return temp;
    } else {
        cout << "No items in stack to pop." << endl;
        exit(1);
    }
}

int Stack::size() {
    return data.size();
}


