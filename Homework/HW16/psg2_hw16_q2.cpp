#include <iostream>
#include "Queue.h"

int main() {
    using namespace std;


    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    Queue<int> copy = q;

    int output;

    q.pop(output);
    q.pop(output);


    cout << "Un-popped queue:" << std::endl;
    while (copy.pop(output)) {
        cout << output << std::endl;
    }

    cout << "\n\n";


    cout << "Popped queue:" << std::endl;
    while (q.pop(output)) {
        cout << output << std::endl;
    }

}