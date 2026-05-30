// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool checks(vector<int>& check, int endlimit, int blockSize)
// {
//     int cnt = 0;

//     endlimit = min(endlimit, (int)check.size() - 1);

//     for (int i = 0; i <= endlimit; i++)
//     {
//         if (check[i] != -1)
//             cnt++;
//         else
//             cnt = 0;

//         if (cnt >= blockSize)
//             return true;
//     }

//     return false;
// }

// void blockQueries(vector<bool>& ans,
//                   vector<int>& check,
//                   vector<vector<int>>& queries)
// {
//     for (auto &q : queries)
//     {
//         if (q[0] == 1)
//         {
//             int pos = q[1];

//             if (pos >= 0 && pos < check.size())
//                 check[pos] = -1;
//         }
//         else
//         {
//             int endlimit = q[1];
//             int blockSize = q[2];

//             ans.push_back(
//                 checks(check, endlimit, blockSize)
//             );
//         }
//     }
// }

// int main()
// {
//     vector<vector<int>> queries =
//     {
//         {1,7},
//         {2,7,6},
//         {1,2},
//         {2,7,5},
//         {2,7,6}
//     };

//     int maxi = 0;

//     for (auto &q : queries)
//         for (int x : q)
//             maxi = max(maxi, x);

//     vector<int> check(maxi + 1, 0);

//     vector<bool> ans;

//     blockQueries(ans, check, queries);

//     for (bool x : ans)
//         cout << x << " ";

//     cout << endl;

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int n) : n(n) {
            tree.assign(4 * n + 4, 0);
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                update(node * 2, l, mid, idx, val);
            else
                update(node * 2 + 1, mid + 1, r, idx, val);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        void update(int idx, int val) {
            update(1, 0, n, idx, val);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) >> 1;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }

        int query(int l, int r) {
            if (l > r)
                return 0;

            return query(1, 0, n, l, r);
        }
    };

public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        SegTree seg(MAXX);

        auto it = obstacles.begin();

        while (next(it) != obstacles.end()) {
            int L = *it;
            int R = *next(it);

            seg.update(R, R - L);
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {

            auto &q = queries[i];

            if (q[0] == 1) {

                int x = q[1];

                auto cur = obstacles.find(x);

                int L = *prev(cur);
                int R = *next(cur);

                obstacles.erase(cur);

                seg.update(x, 0);
                seg.update(R, R - L);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int prevObstacle = *prev(it);

                int bestGap = seg.query(0, prevObstacle);
                bestGap = max(bestGap, x - prevObstacle);

                ans.push_back(bestGap >= sz);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    vector<vector<int>> queries = {
        {1,7},
        {2,7,6},
        {1,2},
        {2,7,5},
        {2,7,6}
    };

    Solution obj;

    vector<bool> ans = obj.getResults(queries);

    cout << "Output:\n";

    for (bool x : ans)
        cout << (x ? "true" : "false") << " ";

    cout << endl;

    return 0;
}