#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> board={{1,1,1},{1,0,1},{1,1,1}};
   
    bool firstcol=false,firstrow=false;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]==0)
            {
                if(i==0) firstrow=true;
                if(j==0) firstcol=true;
                board[0][j]=0;
                board[i][0]=0;
            }
        }
    }
    for(int i=1;i<board.size();i++)
    {
        for(int j=1;j<board[0].size();j++)
        {
            if(board[i][0]==0||board[0][j]==0)
            {
              board[i][j]=0;
            }
        }
    }
    if(firstrow)
        for(int i=0;i<board.size();i++) board[i][0]=0;
    if(firstcol)
        for(int i=0;i<board.size();i++) board[0][i]=0;


     for(int i=0;i<board.size();i++)
     {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
     }   
}