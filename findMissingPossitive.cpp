#include<iostream>
// #include<vector>
#include<algorithm>
using namespace std;

// int MissingPositive(vector<int>& nums)
// {
//     //if(nums.size()<2) return 0;
//     int check,ans;
//     int min=INT_MAX,max=INT_MIN;
//     for(int i=0; i<=nums.size() && nums[i]>=1;i++)
//     {
//         min=min>nums[i]?nums[i]:min;
//         max=max<nums[i]?nums[i]:max;
//         ans^=nums[i]; 
//     }
//     for(int j=min;j<=max;j++)
//     {
//         check^=j;
//     }
//     return ans^check;
// }
// int main()
// {
//     vector<int> arr={3,4,-1,1,5};
//     int n=5;
//     sort(arr.begin(),arr.end());
//     for(int i = 0; i < n; i++)
//     {
//         if(arr[i] != i + 1){
//             cout<<i + 1;
//             break;}
//     }
//     cout<<n + 1;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {3,4,-1,1,5};

    sort(arr.begin(), arr.end());

    int expected = 1;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= 0) continue;        // ignore negatives

        if(arr[i] == expected)
        {
            expected++;                  // move to next expected
        }
        else if(arr[i] > expected)
        {
            cout << expected;
            return 0;
        }
    }

    cout << expected;
}
