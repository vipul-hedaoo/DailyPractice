#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> array={1,2,3,4,3,4,2,1,4,3,1,5,6,7,8,9,9,9};
    sort(array.begin(),array.end());
    int i=0,j=1;
    vector<int>ans;
    ans.push_back(array[0]);
    while(j<array.size())
    {
        if(array[i]==array[j])j++;
        else{
           ans.push_back(array[j]);
           i=j;
        }
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<"  ";
}