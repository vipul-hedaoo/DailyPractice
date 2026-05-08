#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
void backtrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int st,unordered_set<string>& memo)
{
    string str;
    for(int i=0;i<temp.size();i++)
    {
      str+=to_string(temp[i]);
    }
    if(memo.find(str)==memo.end())
    {
        memo.insert(str);
        ans.push_back(temp);
    }

    for(int i=st;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums,ans,temp,i+1,memo);
        temp.pop_back();
    }
}
int main()
{
    vector<int>nums={1,2,2};
    unordered_set<string> memo;   
    vector<vector<int>>ans;
    vector<int>temp;
    backtrack(nums,ans,temp,0,memo);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}