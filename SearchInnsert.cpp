# include<iostream>
# include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int length=nums.size();
        if(length< 1)
            return 0;
        for(int i=0;i<length;i++)
        {
            if(nums[i]==target) return i;
            else if(nums[i]>target) return i;
        }
        return length;
    }
int main()
{
    vector<int> a={2,4,6,8,10};
    int target=12;
    cout<<searchInsert(a,target)<<endl;
}