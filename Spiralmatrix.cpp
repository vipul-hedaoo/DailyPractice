// #include<iostream>
// #include<vector>
// using namespace std;
// void right(vector<vector<int>> &board,int i, int n ,int j,vector<int> &ans)
// {
//   for(int l=j;l<n;l++)
//   {
//     ans.push_back(board[i][l]);
//   }
// }
// void down(vector<vector>int>> &board,int i, int n ,int j,vector<int> &ans)
// {
//     for(int l=i;l<n;l++)
//     {
//         ans.push_back(board[l][j]);
//     }
// }
// void left(vector<vector<int>> &board,int i, int n ,int j,vector<int> &ans)
// {
//     for(int l=j;l>n;l--)
//     {
//         ans.push_back(board[i][l]);
//     }
// }
// void up(vector<vector<int>> &board,int i, int n ,int j,vector<int> &ans)
// {
//     for(int l=i;l>n;l--)
//     {
//         ans.push_back(board[l][j]);
//     }
// }

// void spiral(vector<vector<int>> &board, vector<int> &ans)
// {
//     int top = 0;
//     int bottom = board.size() - 1;
//     int left = 0;
//     int right = board[0].size() - 1;

//     while (top <= bottom && left <= right)
//     {
//         // left → right
//         for (int i = left; i <= right; i++)
//             ans.push_back(board[top][i]);
//         top++;

//         // top → bottom
//         for (int i = top; i <= bottom; i++)
//             ans.push_back(board[i][right]);
//         right--;

//         // right → left
//         if (top <= bottom)
//         {
//             for (int i = right; i >= left; i--)
//                 ans.push_back(board[bottom][i]);
//             bottom--;
//         }

//         // bottom → top
//         if (left <= right)
//         {
//             for (int i = bottom; i >= top; i--)
//                 ans.push_back(board[i][left]);
//             left++;
//         }
//     }
// }
// void printl(vector<int> & ans)
// {
//     for(int i=0;i<ans.size();i++)
//     {
//         cout<<ans[i];
//     }
// }
// int main()
// {
//     vector<vector<int>> board={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//     vector<int> ans;
//     spiral(board,ans);
//    // printl(ans);
// }


#include<iostream>
#include<vector>
using namespace std;

void spiral(vector<vector<int>> &board, vector<int> &ans)
{
    if(board.empty()) return;

    int top = 0;
    int bottom = board.size() - 1;
    int left = 0;
    int right = board[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(board[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(board[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(board[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(board[i][left]);
            left++;
        }
    }
}

void printl(vector<int> &ans)
{
    for(int x : ans)
        cout << x << " ";
}

int main()
{
    vector<vector<int>> board = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int> ans;
    spiral(board, ans);
    printl(ans);
}