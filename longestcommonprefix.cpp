#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> strs) {
    if (strs.empty()) return "";

    sort(strs.begin(), strs.end());

    string first = strs.front();
    string last  = strs.back();

    int i = 0;
    while (i < first.length() && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}
int main()
{
    int n;
    cout<<"enetr";
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    cout<<longestCommonPrefix(strs);
    return 0;
}