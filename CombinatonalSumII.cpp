
# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

void solve(vector<int>& array,int target, int start,vector<int>& temp,vector<vector<int>>& ans)
{
    if(!target){
        ans.push_back(temp);
        return;
    }
    for(int i=start;i<array.size();i++)
    {
        if(i > start && array[i] == array[i-1]) continue;
        if(array[i]>target) break;
        temp.push_back(array[i]);
        solve(array,target-array[i],i+1,temp,ans);
        temp.pop_back();
    }

}

int main()
{
    vector<int> arr={2,5,2,1,2};
        int target=5;
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,target,0,temp,ans);
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