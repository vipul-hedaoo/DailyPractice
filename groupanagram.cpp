#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> array = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> mp;

    for(auto str : array)
    {
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(str);
    }

    for(auto &group : mp)
    {
        for(auto &word : group.second)
            cout << word << " ";
        cout << endl;
    }
}