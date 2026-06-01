#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumcost(vector<int>& arr)
{
    int cost = 0;

    if (arr.size() <= 2)
    {
        size_t i = 0;

        while (i < arr.size())
        {
            cost += arr[i];
            i++;
        }

        return cost;
    }

    for (int i = (int)arr.size() - 1, k = 1; i >= 0; i--, k++)
    {
        if (k % 3 != 0)
        {
            cost += arr[i];
        }
    }

    return cost;
}

int main()
{
    vector<int> arr = {5,5,5};

    sort(arr.begin(), arr.end());

    cout << minimumcost(arr);

    return 0;
}