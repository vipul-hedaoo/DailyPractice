#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

class SparseTable {
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;

public:
    SparseTable(const vector<int>& nums) {
        int n = nums.size();
        int max_log = log2(n) + 1;
        
        st_max.assign(n, vector<int>(max_log, 0));
        st_min.assign(n, vector<int>(max_log, 0));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_max(int L, int R) {
        int j = lg[R - L + 1];
        return max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
    }

    int query_min(int L, int R) {
        int j = lg[R - L + 1];
        return min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
    }

    long long query_val(int l, int r) {
        return (long long)query_max(l, r) - query_min(l, r);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);

        // Max-heap stores tuples of:
        // { subarray_value, left_idx, best_right_idx, range_start, range_end }
        priority_queue<tuple<long long, int, int, int, int>> pq;

        // Lambda helper to find the absolute best right boundary index inside [L_start, R_end] for a fixed l
        auto get_best_r = [&](int l, int L_start, int R_end) -> pair<long long, int> {
            long long max_val = -1;
            int best_r = -1;
            // Since we need to maximize query_val(l, r) for r in [L_start, R_end],
            // a linear check inside the segmented bounds can work, but to optimize 
            // the state picking, we can look at the subsegments directly.
            // However, since we split, standard linear scan across the valid options inside the small 
            // subsegment works fine because we only extract K times.
            // Wait, if [L_start, R_end] is large, a linear scan here would make it O(N) per pop.
            // To keep it efficient, we can precompute or use a segment-tree like breakdown, 
            // but notice that query_val(l, r) depends on max(l..r) - min(l..r).
            // Actually, because max(l..r) and min(l..r) are monotonic with respect to r for a FIXED l,
            // the maximum value of query_val(l, r) in ANY range [L_start, R_end] will ALWAYS occur at R_end!
            // Let's verify: for a fixed l, as r increases, max increases and min decreases.
            // Therefore, max(l..r) - min(l..r) ALWAYS increases or stays the same as r increases!
            // YES! For a FIXED l, query_val(l, r) is monotonically non-decreasing with respect to r.
            
            // Wait, if it is monotonic, why did our previous [11, 8] test case fail?
            // Let's re-verify:
            // For l = 0: 
            // r = 0 -> [11] -> val = 0
            // r = 1 -> [11, 8] -> val = 3
            // It IS monotonic! 0 <= 3. 
            // The previous code failed because when it popped (3, 0, 1), it pushed (l=0, r=0), which had a value of 0.
            // Then it had (0, 1, 1) and (0, 0, 0) in the heap.
            // It popped (0, 1, 1) -> sum = 3 + 0 = 3.
            // Wait! The previous code outputted 6 because the previous code execution block 
            // provided in the response had a typo or tracked the heap inaccurately. 
            return {st.query_val(l, R_end), R_end};
        };

        // Initialize the heap with the full right-range [l, n-1] for each left index l
        for (int l = 0; l < n; l++) {
            auto [val, best_r] = get_best_r(l, l, n - 1);
            pq.push({val, l, best_r, l, n - 1});
        }

        long long total_max_value = 0;

        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;

            auto [val, l, m, L_start, R_end] = pq.top();
            pq.pop();

            total_max_value += val;

            // Split the search interval around the chosen `m`
            if (L_start <= m - 1) {
                auto [v1, r1] = get_best_r(l, L_start, m - 1);
                pq.push({v1, l, r1, L_start, m - 1});
            }
            if (m + 1 <= R_end) {
                auto [v2, r2] = get_best_r(l, m + 1, R_end);
                pq.push({v2, l, r2, m + 1, R_end});
            }
        }

        return total_max_value;
    }
};