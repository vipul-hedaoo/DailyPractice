#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
    int longestValidParentheses(string s) {
        if(s.length()==0) return 0;
        stack<int> ironman;
        ironman.push(-1);
        int result=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='(')
            {
              ironman.push(i);
            }
            else
            {
                ironman.pop();
                if(ironman.empty())
                {ironman.push(i);}
                else
                {result=max(result,(i-ironman.top()));};
            }
        }

    // //     return result;
    // stack<int> st;
    // st.push(-1);   // base index
    // int result = 0;

    // for(int i = 0; i < s.length(); i++)
    // {
    //     if(s[i] == '(')
    //     {
    //         st.push(i);
    //     }
    //     else
    //     {
    //         st.pop();

    //         if(st.empty())
    //         {
    //             st.push(i);
    //         }
    //         else
    //         {
    //             result = max(result,( i - st.top()));
    //         }
    //     }
    // }

    return result;
}
int main(){
    string a="()()((()";
    cout<<longestValidParentheses(a);
}