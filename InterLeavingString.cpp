// #include<iostream>
// #include<vector>
// #include<string>
// #include<stack>
// using namespace std;
// int main()
// {
//  string s1="aabcc";
//  string s2="dbbca";
//  string s3="aadbbbaccc";
//  if(s1.length()+s2.length()!=s3.length())
//  {
//      cout<<"false";
//      return 0;
//  }
//     stack<char> st1,st2;
//     for(char c:s1)
//     {
//         st1.push(c);
//     }
//     for(char c:s2)
//     {
//         st2.push(c);
//     }
//     for(int i=s3.length()-1;i>=0;i--)
//     {
//         if(!st1.empty() && st1.top()==s3[i])
//         {
//             st1.pop();
//         }
//         else if(!st2.empty() && st2.top()==s3[i])
//         {
//             st2.pop();
//         }
//         else
//         {
//             cout<<"false";
//             return 0;
//         }
//     }
//     cout<<"true";   
// }

#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool solvestring(stack<char>& st1,stack<char>& st2,string s3)
{
    while(!st1.empty()||!st2.empty())
    {
        if(!st1.empty() && st1.top()==s3.back())
        {
            st1.pop();
            s3.pop_back();
            solvestring(st1,st2,s3);
        }
        else if(!st2.empty() && st2.top()==s3.back())
        {
            st2.pop();
            s3.pop_back();
            solvestring(st2,st1,s3);
        }
        else
        {
            //cout<<"false";
            return false;
        }
    }
    return true;
}
int main()
{
 string s1="aabcc";
 string s2="dbbca";
 string s3="aadbbcbcac";
 if(s1.length()+s2.length()!=s3.length())
 {
     cout<<"false";
     return 0;
 }
    stack<char> st1,st2;
    for(char c:s1)
    {
        st1.push(c);
    }
    for(char c:s2)
    {
        st2.push(c);
    }
    bool ans=solvestring(st1,st2,s3);
    cout<<ans;
}
