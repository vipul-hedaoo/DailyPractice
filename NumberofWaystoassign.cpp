#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = 0;

        function<void(int, int, int)> dfs = [&](int u, int parent, int depth) {
            maxDepth = max(maxDepth, depth);

            for (int v : adj[u]) {
                if (v != parent) {
                    dfs(v, u, depth + 1);
                }
            }
        };

        dfs(1, 0, 0);

        return (int)modPow(2, maxDepth - 1);
    }
};

int main() {
    int m; // number of edges
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    cout << sol.assignEdgeWeights(edges) << endl;

    return 0;
}