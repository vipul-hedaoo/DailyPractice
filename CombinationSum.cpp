#include<iostream>
#include <set>
#include <vector>
using namespace std;

set<vector<int>> s;
void combinationsum(vector<int>& arr, int target,int ind,vector<int>& combin,vector<vector<int>>& ans)
{
        if(ind==arr.size() || target<0)
        {
           return;
        }
        if(target==0)
        {
          if(s.find(combin)==s.end())
            {
                ans.push_back({combin});
                s.insert(combin);
            }
            return;
        }
        combin.push_back(arr[ind]);
        combinationsum(arr,target-arr[ind],ind+1,combin,ans);
        combinationsum(arr,target-arr[ind],ind,combin,ans);
        combin.pop_back();
        combinationsum(arr,target,ind+1,combin,ans);
    }
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>>ans;
        int ind=0;
        combinationsum(candidates,target,ind,combination,ans);
        return ans;
    
    }
    int main(){
        vector<int> arr={2,3,6,7};
        int target=4;
        vector<vector<int>> ans=combinationSum(arr,target);
        cout<<"[";
        for(int i =0;i<ans.size();i++)
        { cout<<"[";
            for(int j=0;j<ans[i].size();j++)
            {
             cout<<ans[i][j]<<" ";
            }
          cout<<"] ";
        }
        cout<<"]";
}