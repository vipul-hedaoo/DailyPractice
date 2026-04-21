#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "1011";
    string b = "1101";

    string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if(i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if(j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    cout << "Result: " << result << endl;
    return 0;
}