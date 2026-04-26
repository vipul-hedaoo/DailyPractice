//stirng palindrome

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string str="RAmar";
    int i = 0, j = str.size() - 1;
    while(i < j)
    {
        if(tolower(str[i]) != tolower(str[j]))
        {
            cout << "Not a palindrome";
            return -1;
        }
        i++;
        j--;
    }
    cout << "String is palindrome";
    return 0;
}