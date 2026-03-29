#include<iostream>
#include<vector>
using namespace std;
void swap(vector<vector<int>>& array,int i,int r,int j ,int k)
{
    array[i][r]=array[i][r]^array[j][k];
    array[j][k]=array[i][r]^array[j][k];
    array[i][r]=array[i][r]^array[j][k];
}
int main()
{
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
//    row ->colum
int n=mat.size();
   vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                temp[j][n - 1 - i] = mat[i][j];

        mat = temp;

   for(size_t i = 0; i < mat.size(); i++)
    {
      for(size_t j = 0; j < mat[i].size(); j++) 
    {
        cout << mat[i][j] << " ";
    }
    cout << endl;
    }
}