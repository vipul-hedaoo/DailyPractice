#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void backtrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int st)
{
  
        ans.push_back(temp);

    for(int i=st;i<nums.size();i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums,ans,temp,i+1);
        temp.pop_back();
    }
}
int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>>ans={{ }};
    vector<int>temp;
    backtrack(nums,ans,temp,0);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}