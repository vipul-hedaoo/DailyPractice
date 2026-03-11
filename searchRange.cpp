#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1,-1};
    int first = -1, last = -1;
    for(int i = 0; i < (int)nums.size(); i++)
    {
        if(nums[i] == target)
        {
            first==-1?first=i:last=i;
        }
    }
        ans[0] = first;
        ans[1] = last;
        return ans;
}
int main()
{
    vector<int> a = {5,5,5,6,7,8,9,9,9,9,10};
    int target = 9;

    vector<int> res = searchRange(a, target);

    cout << res[0] << " " << res[1] << endl;
}