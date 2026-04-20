#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> digits={1,9,9};
    int i=digits.size()-1;
        int carry=1,num=0;
        while(i>=0)
        {
            num=digits[i]+carry;
            if(num>9)
            {
              carry=1;
              digits[i]=0;
            }
            else{
                digits[i]=num;
                carry=0;
                break;
            }
            i--;
        }
        for(int i=0;i<digits.size();i++)
        {
            cout<<digits[i]<<" ";
        }
}