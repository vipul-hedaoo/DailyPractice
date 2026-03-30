#include <iostream>
#include<cmath>
using namespace std;
double simplepow(double number,int power)
{
    return pow(number,power);
}
int main() {
    double num = 2.0;
    int power = -2;
    double result = 1.0;
    int p = power;
    // Handle negative power
    if (p < 0) {
        p = -p;
    }
    // Calculate power
    for (int i = 0; i < p; i++) {
        result *= num;
    }
    // If original power was negative
    if (power < 0) {
        result = 1 / result;
    }
    cout << result;
 //cout<<simplepow(2,-2);
 }


////
