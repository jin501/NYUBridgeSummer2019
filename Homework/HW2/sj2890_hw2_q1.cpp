#include <iostream>
using namespace std;

int main() {

    int numberOfQuarters, numberOfDimes, numberOfNickles, numberOfPennies;

    cout << "Please enter number of coins:" << endl;

    // prompt and store user input
    cout << "# of quarters: ";
    cin >> numberOfQuarters;

    cout << "# of dimes: ";
    cin >> numberOfDimes;

    cout << "# of nickles: ";
    cin >> numberOfNickles;

    cout << "# of pennies: ";
    cin >> numberOfPennies;

    // value of various types of money
    const int CENTS_TO_DOLLAR = 100;
    const int QUARTER_VALUE = 25;
    const int DIME_VALUE = 10;
    const int NICKEL_VALUE = 5;
    // convert user input numbers into money value
    int amountInQuarters, amountInDimes, amountInNickles, amountInPennies;
    amountInQuarters = numberOfQuarters * QUARTER_VALUE;
    amountInDimes = numberOfDimes * DIME_VALUE;
    amountInNickles = numberOfNickles * NICKEL_VALUE;
    amountInPennies = numberOfPennies;

    int totalDollars, centsLeftover, totalCents;
    totalCents = amountInQuarters + amountInDimes + amountInNickles + amountInPennies;
    centsLeftover = totalCents % CENTS_TO_DOLLAR;
    totalDollars = totalCents / CENTS_TO_DOLLAR;

    cout << "The total is " << totalDollars << " dollars and " << centsLeftover << " cents" << endl;

    return 0;
}