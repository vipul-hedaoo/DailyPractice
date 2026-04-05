#include<iostream>
#include<vector>
#include<regex>
using namespace std;

int main()
{
    string s="hello world   ijk  ";
    stringstream ss(s);
    string items;
    vector<string> result;
    while(getline(ss,items,' '))
    {
        if(items!="")
          result.push_back(items);
    }
    if(result.empty()) cout<<0;
    string ans=result[result.size()-1];
    // return ans.size();
    cout<<ans.size();
}