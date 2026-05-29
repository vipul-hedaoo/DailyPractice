#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int min=INT32_MAX,sum=0;
    vector<int> arr={999,19,990};
    for(int num:arr)
    {
        sum=0;
        if(num==0) 
        { 
            min=0;
            break;
        }
        int i=num;
        while(i>0)
        {
          sum+=i%10;
          i=i/10;
        }
        if(sum<min)
        {
            min=sum;
        }
    }
    cout<<min;
}