#include <iostream>
using namespace std;

int main()
{
    int units = 100, quantity = 10;
    int total = 0, ans = 0, discount = 0;

    cout << "Please enter the No of Units :- ";
    cin >> units;

    cout << "Enter the quantity :- ";
    cin >> quantity;

    total = units * quantity;

    if(total > 2000)
    {
        discount = (total * 15) / 100;
        ans = total - discount;
    }
    else
    {
        ans = total;
    }

    cout << "Total amount :- " << total << endl;
    cout << "Discount :- " << discount << endl;
    cout << "Payable Amount :- " << ans << endl;

    return 0;
}