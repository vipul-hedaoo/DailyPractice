#include<iostream>
#include<vector>
using namespace std;

int maxjump(vector<int>& arr)
{
    // int start=0,max=0,count=0;
    // while(start<arr.size()-1)
    // {
    //     int jump=arr[start],k=0;
    //     max=0;
    //     // if(!((start+jump)<arr.size())) 
    //     for(int i=1;i<=jump;i++)
    //     {
    //         if(arr.size()-1<=start+jump)
    //         {
    //             return count+1;
    //         }
    //         else if(max<=arr[start+i])
    //         {
    //             max=arr[start+i];
    //             k=i;
    //         }
    //     }
    //     count++;
    //     if((start+k)<=arr.size()-1) start+=k;
    //     else return count+1;
    // }
    // return count;
    int start = 0, maxReach = 0, count = 0;

while (start < arr.size() - 1)
{
    int jump = arr[start], k = 0;
    maxReach = 0;

    // If we can directly reach end
    if (start + jump >= arr.size() - 1)
        return count + 1;

    for (int i = 1; i <= jump; i++)
    {
        int reach = start + i + arr[start + i];

        if (reach > maxReach)
        {
            maxReach = reach;
            k = i;
        }
    }

    start += k;
    count++;
}

return count;
}
int main()
{
    vector<int> array={3,2,1};
    cout<<maxjump(array);

}