#include <iostream>
using namespace std;

const int CENTS_TO_DOLLAR = 100;
const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;

int main() {

    int dollarInputAmount, centInputAmount;
    int dollarToCents, totalCentAmount;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollarInputAmount >> centInputAmount;

    cout << dollarInputAmount << " dollars and " << centInputAmount << " cents are:" << endl;

    // convert dollars to cents
    dollarToCents = dollarInputAmount * CENTS_TO_DOLLAR;

    // Get total cent amount to be able to calculate minimum coin amounts
    totalCentAmount = dollarToCents + centInputAmount;

    int minQuarterAmount, minDimeAmount, minNickelAmount, minPennyAmount;
    // divide the total cents by quarter value to find out how many quarters. then do same for dimes, nickels, pennies
    minQuarterAmount = totalCentAmount / QUARTER_VALUE;
    minDimeAmount = (totalCentAmount - minQuarterAmount * QUARTER_VALUE) / DIME_VALUE;
    minNickelAmount = (totalCentAmount - minQuarterAmount * QUARTER_VALUE - minDimeAmount * DIME_VALUE) /
                      NICKEL_VALUE;
    minPennyAmount = (totalCentAmount - minQuarterAmount * QUARTER_VALUE - minDimeAmount * DIME_VALUE -
                      minNickelAmount * NICKEL_VALUE) / PENNY_VALUE;
    
    // print out the results
    cout << minQuarterAmount << " quarters, " << minDimeAmount << " dimes, " << minNickelAmount << " nickels";
    cout << " and " << minPennyAmount << " pennies" << endl;

    return 0;
}