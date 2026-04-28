#include<iostream>
#include<vector>
// #include<algorithm>
#include<stack>
#include<sstream>
using namespace std;
int main()
{
    string str="/home/foo/../bar////c";
    stack<string> st;
    stringstream ss(str);
    string token;
    while(getline(ss,token,'/'))
    {
        if(token=="" || token==".")
        {
            continue;
        }
        else if(token=="..")
        {
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(token);
        }
    }
    vector<string> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    string result = "/";
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        result += ans[i];
        if(i != 0)
        {
            result += "/";
        }
    }
    cout << result << endl;
    //return result;
}