#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;

    struct Node {
        long long cnt;
        long long wav;
    };

    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev1, int prev2, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev1 + 1][prev2 + 1][started]) {
            return dp[pos][prev1 + 1][prev2 + 1][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, -1, -1, false, ntight);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            } else {
                int add = 0;

                if (started && prev2 != -1) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                Node nxt = dfs(
                    pos + 1,
                    d,
                    started ? prev1 : -1,
                    true,
                    ntight
                );

                totalCnt += nxt.cnt;
                totalWav += nxt.wav + nxt.cnt * add;
            }
        }

        Node res = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][prev1 + 1][prev2 + 1][started] = true;
            dp[pos][prev1 + 1][prev2 + 1][started] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, -1, -1, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        auto melidroni = make_pair(num1, num2);
        return solve(num2) - solve(num1 - 1);
    }
};

int main() {
    long long num1, num2;
    cin >> num1 >> num2;

    Solution obj;
    cout << obj.totalWaviness(num1, num2) << '\n';

    return 0;
}