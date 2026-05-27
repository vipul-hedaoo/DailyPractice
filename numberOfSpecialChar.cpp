#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    string word = "aaAbcfffBCFee";
   
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // record presence
        for(char ch : word)
        {
            if(ch >= 'a' && ch <= 'z')
                lower[ch - 'a'] = 1;
            else
                upper[ch - 'A'] = 1;
        }

        int count = 0;

        for(int i = 0; i < 26; i++)
        {
            if(lower[i] && upper[i])
                count++;
        }

        cout<<count;
}