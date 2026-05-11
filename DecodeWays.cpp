#include<iostream>
#include<string>
#include<vector>

using namespace std;

void solveBacktrack(string s,
                    vector<vector<string>>& ans,
                    vector<string>& temp,
                    int start)
{
    // Base Case
    if(start == s.length())
    {
        ans.push_back(temp);
        return;
    }

    string str = "";

    for(int i = start; i < s.length(); i++)
    {
        str += s[i];

        int num = stoi(str);

        // Valid range check
        if(num >= 1 && num <= 26)
        {
            temp.push_back(str);

            solveBacktrack(s, ans, temp, i + 1);

            temp.pop_back();
        }
        else
        {
            break;
        }
    }
}

int numDecodings(string s) {
        int n = s.length();

    if(n == 0 || s[0] == '0')
        return 0;

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        // Single digit
        int oneDigit = s[i - 1] - '0';

        if(oneDigit >= 1)
            dp[i] += dp[i - 1];

        // Two digit
        int twoDigit =
            (s[i - 2] - '0') * 10 +
            (s[i - 1] - '0');

        if(twoDigit >= 10 && twoDigit <= 26)
            dp[i] += dp[i - 2];
    }

    return dp[n];
    }

int main()
{
    string s = "1224";

    vector<vector<string>> ans;
    vector<string> temp;

    solveBacktrack(s, ans, temp, 0);

    for(auto &v : ans)
    {
        for(auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << "Total Ways = " << ans.size()<<endl;
    cout << "Total Decodings = " << numDecodings(s);

    return 0;
}