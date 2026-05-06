#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main()
{
    string s1="abcde";
    string s2="caebd";
    if(s1==s2)
    {
        cout<<"Scrambled";
        return 0;
    }
    if(s1.length()!=s2.length())
    {
        cout<<"Not Scrambled";
        return 0;
    }
    unordered_set<char> st;
    for(int i=0;i<s1.length();i++)
    {
        st.insert(s1[i]);
    }
    for(int i=0;i<s2.length();i++)
    {
        if(st.find(s2[i])==st.end())
        {
            cout<<"Not Scrambled";
            return 0;
        }
    }
    cout<<"Scrambled";
    return 1;
}