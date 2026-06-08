#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int num : nums) {
            if (num < pivot)
                less.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                greater.push_back(num);
        }

        vector<int> ans;

        for (int x : less) ans.push_back(x);
        for (int x : equal) ans.push_back(x);
        for (int x : greater) ans.push_back(x);

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int pivot;
    cin >> pivot;

    Solution obj;
    vector<int> ans = obj.pivotArray(nums, pivot);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}