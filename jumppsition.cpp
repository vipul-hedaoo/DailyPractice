#include<iostream>
#include<vector>
using namespace std;

bool jump(vector<int> &array, int ind, int n, vector<int> &dp)
{
    if(ind == n) return true;

    if(dp[ind] != -1) return dp[ind];

    for(int i = ind + 1; i <= ind + array[ind] && i <= n; i++)
    {
        if(jump(array, i, n, dp))
            return dp[ind] = 1;
    }

    return dp[ind] = 0;
}

int main()
{
    vector<int> arr = {2,3,1,1,4};
    vector<int> dp(arr.size(), -1);
    cout<<"v";
    cout << jump(arr, 0, arr.size() - 1, dp);
}