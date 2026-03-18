#include <iostream>
using namespace std;

string countandsay(string str, int target)
{
    if (target == 1) return str;
    int k = stoi(str);
    string ans = "";
    int count = 1;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            ans += to_string(count);
            ans += str[i - 1];
            count = 1;
        }
    }

    // Add last group
    ans += to_string(count);
    ans += str.back();

    return countandsay(ans, target - 1);
}

int main()
{
    int target = 4;
    cout << countandsay("1", target);
}