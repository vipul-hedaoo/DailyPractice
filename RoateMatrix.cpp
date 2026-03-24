#include<iostream>
#include<vector>
using namespace std;
 bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // if(mat.size()!=target.size() || mat[0].size()!=target[0].size()) return false;
        // for(int i=0;i<mat.size();i++)
        // {
        //     for(int j=0;j<mat[0].size();j++)
        //     {
        //         if(mat[i][j]!=target[j][target.size()-1-i]){
        //            // cout<<"fasle ";
        //            return false;
        //         }
        //     }
        // }
        // return true;
        int n = mat.size();

    for(int k = 0; k < 4; k++) {

        bool same = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != target[i][j]) {
                    same = false;
                    break;
                }
            }
        }

        if(same) return true;

        // rotate 90° clockwise
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                temp[j][n - 1 - i] = mat[i][j];

        mat = temp;
    }

    return false;
    }
int main()
{
 vector<vector<int>> org={{0,0,0},{0,1,0},{1,1,1}};
 vector<vector<int>> target={{1,1,1},{0,1,0},{0,0,0}};
 cout<<findRotation(org,target);
}
