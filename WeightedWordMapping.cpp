#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            ans.push_back('z' - (sum % 26));
        }

        return ans;
    }
};

int main() {
    vector<string> words = {"abcd", "def", "xyz"};

    vector<int> weights = {
        5,3,12,14,1,2,3,2,10,6,6,9,7,
        8,7,10,8,9,6,9,9,8,3,7,7,2
    };

    Solution obj;
    cout << obj.mapWordWeights(words, weights) << endl;

    return 0;
}