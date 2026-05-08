#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int btoi(string s)
{
    int num=0;
    for(int i=0;i<s.length();i++)
    {
        num=num*2+(s[i]-'0');
    }
    return num;
}
void BacktrackGrayCode(int n,vector<int>&ans,string temp,bool rev)
{
    if(temp.length()==n)
    {
        ans.push_back(btoi(temp));
        return;
    }
    if(!rev)
    {
        BacktrackGrayCode(n,ans,temp+"0",false);
        BacktrackGrayCode(n,ans,temp+"1",true);
    }
    else{
        BacktrackGrayCode(n,ans,temp+"1",false);
        BacktrackGrayCode(n,ans,temp+"0",true);
    }
    
} 

int main()
{
    int n=4;
    vector<int>ans;
    string temp="";
    BacktrackGrayCode(n,ans,temp,false);
    // for(int i=0;i<ans.size();i++)
    // {
    //     ans[i]=btoi(ans[i]);
    // }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}