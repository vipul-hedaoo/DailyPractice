#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// using xor
int findMissingNumber(vector<int> v)
{
    int len=v.size();
    int xoor=v.at(0),all=v.at(0);
    for(int i=1;i<len;i++)
    {
        xoor^=v.at(i);
    }
    for(int j=0;j<len+1;j++)
    {
      xoor^=all;
      all++;
    }
    return xoor;
}
int findMissingNumber2(vector<int> v)
{
    if(v.size()<2) return -1;
    sort(v.begin(),v.end());
    int first=v.at(0),sum=0;
    int len=v.size();
    int last=v.at(len-1);
    
    for(int i=0;i<v.size();i++)
    {
        sum+=v.at(i);
    }
    sum=((last-first+1)*(first+last))/2-sum;
    return sum;
}
int main()
{
  vector<int> v={1,2,6,5,4};
  cout<<findMissingNumber(v)<<endl; 
  cout<<findMissingNumber2(v);
  return 0;
}
