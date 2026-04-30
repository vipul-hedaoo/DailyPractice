//foundDuplicateII
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={1,1,1,1,1,2,2,2,2,2,3,4,4,4};
    if(arr.size()<=2) return arr.size();
    int j=2;
    for(int i=2;i<arr.size();i++)
    {
        if(arr[i]!=arr[j-2])
        {
            arr[j]=arr[i];
            j++;
        }
    }
    //return j;
    
    for(int i=0;i<j;i++)
    {
        cout<<arr[i]<<" ";
    }
}