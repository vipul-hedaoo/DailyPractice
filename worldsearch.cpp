#include<iostream>
#include<vector>
using namespace std;

bool worldSearch(vector<vector<char>> &arr, string word, int row, int col, int index)
{
    // Base case
    if(index == word.size())
        return true;

    // Boundary + mismatch check
    if(row < 0 || col < 0 || row >= arr.size() || col >= arr[0].size() || arr[row][col] != word[index])
        return false;

    char temp = arr[row][col];
    arr[row][col] = '*'; // mark visited

    bool found = worldSearch(arr, word, row+1, col, index+1) ||
                 worldSearch(arr, word, row-1, col, index+1) ||
                 worldSearch(arr, word, row, col+1, index+1) ||
                 worldSearch(arr, word, row, col-1, index+1);

    arr[row][col] = temp; // backtrack

    return found;
}

int main()
{
    vector<vector<char>> v = {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'}
    };

    string word = "ebadg";
    bool result = false;

    // Try all starting points
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[0].size(); j++)
        {
            if(worldSearch(v, word, i, j, 0))
            {
                result = true;
                break;
            }
        }
    }

    cout << result;
}