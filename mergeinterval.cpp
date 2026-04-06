#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>>& array) {
    vector<vector<int>> ans;

    if(array.size() == 0) return ans;

    sort(array.begin(), array.end());

    ans.push_back(array[0]);

    for(size_t i = 1; i < array.size(); i++) {
        if(ans.back()[1] >= array[i][0]) {
            // merge
            ans.back()[1] = max(ans.back()[1], array[i][1]);
        } else {
            // no overlap
            ans.push_back(array[i]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> array = {{1,2},{3,6},{8,10},{15,18}};
    
    vector<vector<int>> ans = mergeInterval(array);

    for(size_t i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "] ";
    }
}