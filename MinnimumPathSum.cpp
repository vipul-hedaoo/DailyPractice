#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<m;i++) grid[0][i]+=grid[0][i-1];
    for(int i=1;i<n;i++) grid[i][0]+=grid[i-1][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            grid[i][j]=min((grid[i][j]+grid[i][j-1]),(grid[i][j]+grid[i-1][j]));
        }
    }
    cout<<grid[n-1][m-1]<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

}