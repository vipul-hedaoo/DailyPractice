#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n*m - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1,3,5},
        {7,9,11},
        {13,15,17}
    };

    cout << searchMatrix(matrix, 9); // 1 (true)
}