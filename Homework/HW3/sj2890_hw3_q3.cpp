#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    int a, b, c;
    string classification;
    double quadraticRoot, positiveQuadraticSol, negativeQuadraticSol;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    if(a == 0 && b == 0 && c != 0) {
        classification = "no solution";
        cout << "This equation has " << classification << endl;
    }
    else if(a == 0) {
        classification = "infinite number of solutions";
        cout << "This equation has " << classification << endl;
    }
    else if(a != 0) {
        quadraticRoot = (b * b - 4 * a * c);
        if(quadraticRoot == 0) {
            classification = "a single real solution";
            positiveQuadraticSol = (-b + sqrt(quadraticRoot)) / (2*a);
            cout << "This equation has " << classification << " x=" << positiveQuadraticSol << endl;
        }
        if(quadraticRoot > 0) {
            classification = "two real solutions";
            positiveQuadraticSol = (-b + sqrt(quadraticRoot)) / (2*a);
            negativeQuadraticSol = (-b - sqrt(quadraticRoot)) / (2*a);
            cout << "This equation has " << classification << " x=" << positiveQuadraticSol << ", " << negativeQuadraticSol << endl;
        }
        if(quadraticRoot < 0) {
            classification = "no real solution";
            cout << "This equation has " << classification << endl;
        }
    }

    return 0;
}
