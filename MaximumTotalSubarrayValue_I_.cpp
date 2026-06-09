#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // Edge case handling
        if (nums.empty()) return 0;
        
        int global_max = nums[0];
        int global_min = nums[0];
        
        for (int num : nums) {
            if (num > global_max) global_max = num;
            if (num < global_min) global_min = num;
        }
        
        // Cast to long long before subtraction to handle extreme values safely
        long long max_single_value = static_cast<long long>(global_max) - global_min;
        
        return max_single_value * k;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard positive and negative numbers
    vector<int> nums1 = {4, 1, 9, -2, 5};
    int k1 = 3;
    // Max: 9, Min: -2 -> Diff: 11 -> Total: 11 * 3 = 33
    cout << "Test Case 1 Result: " << solver.maxTotalValue(nums1, k1) << " (Expected: 33)" << endl;

    // Test Case 2: Array with single element
    vector<int> nums2 = {7};
    int k2 = 5;
    // Max: 7, Min: 7 -> Diff: 0 -> Total: 0 * 5 = 0
    cout << "Test Case 2 Result: " << solver.maxTotalValue(nums2, k2) << " (Expected: 0)" << endl;

    // Test Case 3: Large values to test potential integer overflow
    vector<int> nums3 = {2000000000, -2000000000}; 
    int k3 = 2;
    // Diff: 4,000,000,000 (overflows standard 32-bit signed int)
    // Total: 4,000,000,000 * 2 = 8,000,000,000
    cout << "Test Case 3 Result: " << solver.maxTotalValue(nums3, k3) << " (Expected: 8000000000)" << endl;

    return 0;
}