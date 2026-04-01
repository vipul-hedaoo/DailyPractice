 #include<iostream>
 #include<vector>
 using namespace std;
 bool issafe(vector<string> &board,int row,int col,int n)
    {
        for(int i=0;i<n;i++)
           if(board[row][i]=='Q') return false;
        for(int i=0;i<n;i++)
           if(board[i][col]=='Q') return false;
        for(int i=row,j=col;i>=0 && col>=0;i--,j--)
           if(board[i][j]=='Q') return false;
        for(int i=row,j=col;i>=0 && col<n;i--,j++)
           if(board[i][j]=='Q') return false;
        return true;
    }
void nqueenII(vector<string> &board,int row,int n,int &count)
    {
        if(row==n)
        {
            count++;
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(issafe(board,row,i,n))
            {
                board[row][i]='Q';
                nqueenII(board,row+1,n,count);
                board[row][i]='_';
            }
        }
    }
int totalNQueens(int n) {
        int count=0;
        vector<string> board (n,string(n,'_'));
        nqueenII(board,0,n,count);
        return count;
    }
int main(){
     int n=4;
        cout<<totalNQueens(n);
    }