#include <iostream>
#include <string>
using namespace std;

int main() {
    const double MEMBER_DISCOUNT = .1;

    double priceOfFirstItem, priceOfSecondItem, taxRate;
    string clubCard;
    double bogoDiscount, memberDiscount;
    double basePrice, priceAfterDiscount, totalPrice;

    cout << "Enter price of first item: ";
    cin >> priceOfFirstItem;
    cout << "Enter price of second item: ";
    cin >> priceOfSecondItem;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    basePrice = priceOfFirstItem + priceOfSecondItem;

    if(priceOfSecondItem > priceOfFirstItem) {
        bogoDiscount = (priceOfFirstItem/2 + priceOfSecondItem);
    } else {
        bogoDiscount = (priceOfSecondItem/2 + priceOfFirstItem);
    }

    if(clubCard == "y" || clubCard == "Y") {
        memberDiscount =  bogoDiscount * MEMBER_DISCOUNT;
    }

    priceAfterDiscount = bogoDiscount - memberDiscount;
    totalPrice = priceAfterDiscount + (priceAfterDiscount * (taxRate / 100));

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << priceAfterDiscount << endl;
    cout.precision(5);
    cout << "Total price: " << totalPrice;

    return 0;
}
