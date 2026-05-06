#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<string, bool> dp;

bool isScramble(string s1, string s2)
{
    if(s1 == s2) return true;

    if(s1.length() != s2.length()) return false;

    string key = s1 + " " + s2;
    if(dp.find(key) != dp.end())
        return dp[key];

    // 🔧 Frequency check (pruning)
    vector<int> freq(26, 0);
    for(int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
            return dp[key] = false;
    }

    int n = s1.length();

    // 🔥 Try all partitions
    for(int k = 1; k < n; k++)
    {
        // No swap
        if(isScramble(s1.substr(0, k), s2.substr(0, k)) &&
           isScramble(s1.substr(k), s2.substr(k)))
            return dp[key] = true;

        // Swap
        if(isScramble(s1.substr(0, k), s2.substr(n - k)) &&
           isScramble(s1.substr(k), s2.substr(0, n - k)))
            return dp[key] = true;
    }

    return dp[key] = false;
}

int main()
{
    string s1 = "abcde";
    string s2 = "caebd";

    if(isScramble(s1, s2))
        cout << "Scrambled";
    else
        cout << "Not Scrambled";

    return 0;
}