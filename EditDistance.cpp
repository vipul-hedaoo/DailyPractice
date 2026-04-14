#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s = "horse";
    string s2 = "ros";

    int m = s.size(); 
    int n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    // base cases
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // delete
                    dp[i][j-1],    // insert
                    dp[i-1][j-1]   // replace
                });
            }
        }
    }

    cout << dp[m][n];
}