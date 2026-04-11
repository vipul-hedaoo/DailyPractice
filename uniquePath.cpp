#include<iostream>
#include<vector>
using namespace std;

int possiblePath(int n ,int m,int i,int j ,vector<vector<int>>& board)
{
  if(i==n-1 && j==m-1) return board[i][j];
  board[i][j]=board[i-1][j]+board[i][j-1];
  return possiblePath(n,m,i+1,j,board)+possiblePath(n,m,i,j+1,board);
}
int main()
{
    int n=3,m=7;
    vector<vector<int>> board(n,vector<int>(m,1));
    for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        board[i][j]=board[i-1][j]+board[i][j-1];
    }
    }   
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<board[i][j]<<" ";
    }    cout<<endl;
    }   
    cout<<board[n-1][m-1];

}