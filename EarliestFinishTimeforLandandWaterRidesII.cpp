#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solveOrder(
        vector<int>& firstStart,
        vector<int>& firstDur,
        vector<int>& secondStart,
        vector<int>& secondDur
    ) {
        int m = secondStart.size();

        vector<pair<long long, long long>> rides;
        rides.reserve(m);

        for (int i = 0; i < m; i++) {
            rides.push_back({secondStart[i], secondDur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> sufMinFinish(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1], rides[i].second);
        }

        sufMinFinish[m - 1] = rides[m - 1].first + rides[m - 1].second;
        for (int i = m - 2; i >= 0; i--) {
            sufMinFinish[i] = min(
                sufMinFinish[i + 1],
                rides[i].first + rides[i].second
            );
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)firstStart.size(); i++) {
            long long finishFirst =
                (long long)firstStart[i] + firstDur[i];

            int pos = upper_bound(
                          starts.begin(),
                          starts.end(),
                          finishFirst
                      ) - starts.begin() - 1;

            if (pos >= 0) {
                ans = min(ans,
                          finishFirst + prefMinDur[pos]);
            }

            if (pos + 1 < m) {
                ans = min(ans,
                          sufMinFinish[pos + 1]);
            }
        }

        return ans;
    }

    long long earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration
    ) {
        long long landThenWater =
            solveOrder(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        long long waterThenLand =
            solveOrder(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            );

        return min(landThenWater, waterThenLand);
    }
};

int main() {
    int n, m;

    cin >> n;

    vector<int> landStartTime(n);
    vector<int> landDuration(n);

    for (int i = 0; i < n; i++)
        cin >> landStartTime[i];

    for (int i = 0; i < n; i++)
        cin >> landDuration[i];

    cin >> m;

    vector<int> waterStartTime(m);
    vector<int> waterDuration(m);

    for (int i = 0; i < m; i++)
        cin >> waterStartTime[i];

    for (int i = 0; i < m; i++)
        cin >> waterDuration[i];

    Solution obj;

    cout << obj.earliestFinishTime(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration)
         << endl;

    return 0;
}