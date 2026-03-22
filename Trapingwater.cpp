#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trapingwater(vector<int>& array)
{
    int len=array.size();
    int lmax=0,rmax=0,count=0;
    int left[len];
    int right[len];
    for(int i=0;i<len;i++)
    {
      if(lmax<array[i])
      {
        lmax=array[i];

      }
      left[i]=lmax;
    }
    for(int i=len-1;i>=0;i--)
    {
      if(rmax<array[i])
      {
        rmax=array[i];
      }
      right[i]=rmax;
    }
    for(int i=0;i<len;i++)
    {
        count+=min(left[i],right[i])-array[i];
    }
 return count;
}
int main()
{
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trapingwater(arr);
}