#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    static constexpr int LOG = 18;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;

    void dfs(int u, int p) {
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                a = up[a][j];
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.assign(n + 1, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        dfs(1, 1);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[dist - 1]);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> ans = obj.assignEdgeWeights(edges, queries);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}