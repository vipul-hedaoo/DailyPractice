#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> difference(const vector<int>& arr)
{
    int n = arr.size();
    vector<int> ans(n);

    long long totalSum = 0;

    for (int x : arr)
        totalSum += x;

    long long leftSum = 0;

    for (int i = 0; i < n; i++)
    {
        totalSum -= arr[i]; // now totalSum = rightSum

        ans[i] = abs(leftSum - totalSum);

        leftSum += arr[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 4, 8, 3};

    vector<int> ans = difference(arr);

    for (int num : ans)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}