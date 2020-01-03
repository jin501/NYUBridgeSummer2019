#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    double realNumber;
    int roundingMethod, roundedResult;

    cout << "Please enter a Real number:" << endl;
    cin >> realNumber;
    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;

    switch (roundingMethod) {
        case FLOOR_ROUND:
            roundedResult = realNumber;
            cout << roundedResult;
            break;
        case CEILING_ROUND:
            roundedResult = realNumber + 1;
            cout << roundedResult;
            break;
        case ROUND:
            roundedResult = realNumber + 0.5;
            cout << roundedResult;
            break;
        default:
            cout << "please enter a valid rounding method, 1-3";
            break;
    }
    return 0;
}
