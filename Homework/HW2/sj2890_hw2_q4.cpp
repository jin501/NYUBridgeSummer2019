#include <iostream>
using namespace std;

int main() {

    int firstInt, secondInt;
    int addInts, subInts, multiplyInts, divideInts, moduloInts;
    float divideIntsWithFloat;

    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> firstInt >> secondInt;

    addInts = firstInt + secondInt;
    cout << firstInt << " + " << secondInt << " = " << addInts << endl;

    subInts = firstInt - secondInt;
    cout << firstInt << " - " << secondInt << " = " << subInts << endl;

    multiplyInts = firstInt * secondInt;
    cout << firstInt << " * " << secondInt << " = " << multiplyInts << endl;

    divideIntsWithFloat = (float) firstInt / secondInt;
    cout << firstInt << " / " << secondInt << " = " << divideIntsWithFloat << endl;

    divideInts = firstInt / secondInt;
    cout << firstInt << " div " << secondInt << " = " << divideInts << endl;

    moduloInts = firstInt % secondInt;
    cout << firstInt << " mod " << secondInt << " = " << moduloInts << endl;

    return 0;
}