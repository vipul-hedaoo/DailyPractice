#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp)
{
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];  // already computed

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main()
{
    int N = 10;
    vector<int> dp(N+1, -1);

    for(int i = 0; i < N; i++)
        cout << fib(i, dp) << " ";
}