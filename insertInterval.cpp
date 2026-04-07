#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int>> InsertInterval(vector<vector<int>> &intervals,vector<int> &newinterval)
{
    if(!(newinterval.size())) return intervals;
    vector<vector<int>> ans;
    size_t i=0;
    while(i<intervals.size() && intervals[i][1]<=newinterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }
    while(i<intervals.size() && intervals[i][0]<=newinterval[1])
    {
        newinterval[0]=min(newinterval[0],intervals[i][0]);
        newinterval[1]=max(intervals[i][1],newinterval[1]);
        i++;
    }
    ans.push_back(newinterval);
    while(i<intervals.size())
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> array = {{1,2},{5,6},{8,10},{15,18}};

   // vector<vector<int>> ans = mergeInterval(array);
    vector<int> newInterval = {2,9};
    vector<vector<int>> ans = InsertInterval(array, newInterval);
    for(size_t i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "] ";
    }
}