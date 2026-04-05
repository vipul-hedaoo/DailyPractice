#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> next_permutation(vector<int> &array)
{
    int n=array.size(),ind=-1;

    for(int i=n-2;i>=0;i--)
    { 
        if(array[i]<array[i+1])
        {
          ind=i;
          break;
        }
    }

    if(ind==-1){
      reverse(array.begin(),array.end());
      return array;  
    } 
    for(int i=n-1;i>ind;i--)
    {
        if(array[i]>array[ind])
        {
            swap(array[i],array[ind]);
            break;
        }
    }
    reverse(array.begin()+ind+1,array.end());
    return array;
}
int main()
{
    vector<int> array={1,2,3};
    //next_permutation(array);
    next_permutation(array.begin(),array.end());
    for(size_t i=0;i<array.size();i++)
    {
        cout<<array[i]<<" ";
    }
}