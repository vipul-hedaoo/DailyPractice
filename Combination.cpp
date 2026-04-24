#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& array,
               vector<int>& result, int len, int start)
{
    if(result.size() == len)
    {
        array.push_back(result);
        return;
    }

    for(int i = start; i < nums.size(); i++)   // 🔑 use start
    {
        result.push_back(nums[i]);
        backtrack(nums, array, result, len, i + 1);  // 🔑 move forward
        result.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int len = 2;

    vector<int> result;
    vector<vector<int>> array;

    backtrack(nums, array, result, len, 0);

    for(auto &v : array)
    {
        for(auto x : v)
            cout << x << " ";
        cout << endl;
    }
}