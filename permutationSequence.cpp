#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> backtrack(vector<int>& nums, vector<int>& result ,int k)
{
    if(result.size() == nums.size()&& --k==0)
    {
        return {0};
    }

    for(int number : nums)
    {
        if(find(result.begin(), result.end(), number) != result.end())
            continue;

        result.push_back(number);
        backtrack(nums,result,k);
        result.pop_back();
    }
}
unsigned int factorial(unsigned int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main()
{
    unsigned int n=3,k=3;
    vector<int> nums;
    for(int i=1; i<=n; i++)    {
        nums.push_back(i);
    }
    for(int num : nums) {
        cout << num << " ";
    }
    vector<int> array;
    vector<int> result;
    if(k>factorial(n)) return {};
    array=backtrack(nums,result,k);
    // cout<<to_string(result);
     for(int a:result)
     { 
         cout<<a<<" ";
     }
}