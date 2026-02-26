class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums.at(i)!=val)
           {
            nums.at(ans)=nums.at(i);
            ans++;
           }
        }

        return ans;
    }
};