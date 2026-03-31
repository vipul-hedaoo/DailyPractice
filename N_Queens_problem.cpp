#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<string> &board,int row,int col,int n)
{
   for(int i=0;i<n;i++)
    if(board[row][i]=='Q') return false;
   for(int j=0;j<n;j++)
    if(board[j][col]=='Q') return false;
   for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    if(board[i][j]=='Q') return false;
   for(int i=row,j=col;i>=0 && j<n;i--,j++)
    if(board[i][j]=='Q') return false;
   return true;
}
void queens(vector<string> &board,vector<vector<string>> &ans,int row, int n)
{
    if(row==n)
    {
        ans.push_back({board});
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(issafe(board,row,i,n))
        {
            board[row][i]='Q';
            queens(board,ans,row+1,n);
            board[row][i]='_';
           // queens(board,ans,row-1,n);
        }
    }
}
void print(vector<string> &board ,int n)
{
    for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  vector<string>board(4,string(4,'_'));
  vector<vector<string>>ans;
  int n=4;
  print(board,n);
  queens(board,ans,0,4);
  //print()
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        cout<<ans[i][j]<<" "<<endl;
    }
    cout<<endl;
  }
}