#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
    int maxArea = 0;
    int n = histo.size();

    for(int i = 0; i <= n; i++)
    {
        int currHeight = (i == n) ? 0 : histo[i];

        while(!st.empty() && currHeight < histo[st.top()])
        {
            int height = histo[st.top()];
            st.pop();

            int width;
            if(st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }
    return maxArea;
    }   
int main()
{
    vector<vector<int>> matrix={    
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    //prefixsum
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==1 && i>0)
            {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
    }
    int maxArea=0;
    for(int i=0;i<matrix.size();i++)
    {
        maxArea=max(maxArea,largestRectangleArea(matrix[i]));
    }
 cout<<maxArea;
}
