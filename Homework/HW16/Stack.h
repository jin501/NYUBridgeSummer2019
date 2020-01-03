//
// Created by Peter Geras on 11/2/19.
//

#ifndef HW16_STACK_H
#define HW16_STACK_H

#include <vector>
using namespace std;


class Stack {


private:

    vector<char> data;



public:
    void push(char cha);
    char pop();
    int size();
    char top() const { return data[data.size() - 1];}
};


#endif //HW16_STACK_H
