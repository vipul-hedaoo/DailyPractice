#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> spiralII(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    // if(n==1) return board[0][0]=1;
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int count=1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            board[top][i]=count++;
        top++;

        for (int i = top; i <= bottom; i++)
            board[i][right]=count++;
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                board[bottom][i]=count++;
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
             board[i][left]=count++;
            left++;
        }
    }
    return board;
}

void printl(vector<vector<int>> &ans)
{
    cout << "[\n";
    for(const auto &row : ans) {
        cout << "  [ ";
        for(int val : row) {
            cout << val << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}
 int main()
{
    vector<vector<int>> board ;
    vector<int> ans;
    int c=3;
    board=spiralII(c);
    printl(board);
}