//
// Created by Peter Geras on 11/2/19.
//

#ifndef HW16_QUEUE_H
#define HW16_QUEUE_H

#include <vector>

using namespace std;

template <class T>
class Queue : private vector<T> {

private:
    int begin;
    int vectorSize() const;

public:
    Queue();
    Queue(const Queue& obj);
    void push(int data);
    bool pop(int &out);
    int size();

    Queue& operator = (const Queue &q);
    Queue operator * (unsigned int n);
};


#include "Queue.cpp"

#endif //HW16_QUEUE_H
