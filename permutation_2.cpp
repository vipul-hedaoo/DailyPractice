#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& array, vector<int>& result,vector<bool>& used)
{
    if(result.size() == nums.size() )
    {
        array.push_back(result);
        return;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(used[i])continue;
        if(i > 0 && nums[i] == nums[i-1] && !used[i-1])continue;
        used[i]=true;
        result.push_back(nums[i]);
        backtrack(nums, array, result, used);
        used[i]=false;
        result.pop_back();
    }
}

int main()
{
    vector<int> nums = {1,1,3};
    sort(nums.begin(),nums.end());
    vector<vector<int>> array;
    vector<int> result;
    vector<bool> used2(nums.size(), false);
    // fill(used.begin(),used.end(),false);
    backtrack(nums, array, result,used2);
    
    for(auto &perm : array)
    {
        for(int x : perm)
            cout << x << " ";
        cout << endl;
    }
}