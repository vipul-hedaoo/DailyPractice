#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& array, vector<int>& result)
{
    if(result.size() == nums.size())
    {
        array.push_back(result);
        return;
    }

    for(int number : nums)
    {
        if(find(result.begin(), result.end(), number) != result.end())
            continue;

        result.push_back(number);
        backtrack(nums, array, result);
        result.pop_back();
    }
}

int main()
{
    vector<int> nums = {1,1,3};
    vector<vector<int>> array;
    vector<int> result;

    backtrack(nums, array, result);

    for(auto &perm : array)
    {
        for(int x : perm)
            cout << x << " ";
        cout << endl;
    }
}