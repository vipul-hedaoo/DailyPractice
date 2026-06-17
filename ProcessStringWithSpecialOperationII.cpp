#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size() + 1, 0);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z')
                len[i + 1] = len[i] + 1;
            else if (c == '*')
                len[i + 1] = max(0LL, len[i] - 1);
            else if (c == '#')
                len[i + 1] = len[i] * 2;
            else // '%'
                len[i + 1] = len[i];
        }

        if (k >= len[s.size()])
            return '.';

        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i])
                    return c;
            }
            else if (c == '#') {
                k %= len[i];
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        long long k;

        cin >> s >> k;

        Solution obj;
        cout << obj.processStr(s, k) << "\n";
    }

    return 0;
}