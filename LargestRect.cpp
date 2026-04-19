// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     vector<int> histo={2,1,2,6,2,3};
//     int width=1,lastheight=histo[0],currentheight=0,maxrect=histo[0],ans=0;
//     for(int i=1;i<histo.size();i++)
//     {
//         width++;
//         currentheight=histo[i];
//         ans=min(lastheight,currentheight)*width;
//         maxrect=max(ans,maxrect);
//         lastheight=currentheight;
//         if(histo[i]>=maxrect)
//         {
//           maxrect=histo[i];
//           width=1;
//         }
//     }
//     cout<<maxrect<<endl;
// }


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> histo = {50,4,3,2,1};
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

    cout << maxArea << endl;
    return 0;
}