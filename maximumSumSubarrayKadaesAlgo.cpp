#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubarraySum(vector<int> &nums)
{
    if(nums.size()<=1)  return nums[0];
    int current_max=nums[0],greater_max=nums[0];
    for(size_t i=1;i<nums.size();i++)
    {
        current_max=max(nums[i],(nums[i]+current_max));
        greater_max=max(current_max,greater_max);
    }
   return greater_max;
}
int main()
{
    vector<int> array={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"vipul";
    cout<<maxSubarraySum(array);
}