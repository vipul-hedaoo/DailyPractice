#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    while(!q.empty()){
        auto it = q.front(); q.pop();
        int x = it.first.first;
        int y = it.first.second;
        int time = it.second;

        ans = max(ans, time);

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                grid[nx][ny] = 2;
                q.push({{nx,ny}, time+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }

    return ans;
}
};
int main(){
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(grid) << endl; // Output: 4
    return 0;
}