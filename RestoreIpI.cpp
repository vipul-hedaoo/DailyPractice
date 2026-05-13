// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// void RestoreIP(string s,vector<string>& ans,vector<string>& temp,int curr,int dots)
// {
//     if(curr==s.length() && temp.size()==4)
//     { 
//       ans.push_back(temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3]);
//       return;
//     }
//    // cout<<s.length()<<endl;
//     while(curr<s.length())
//     {
//         string str="";
//         str+=temp[3-dots]+s[curr];
//         int check=stoi(str);
//         if(check<=255 && check>=0)
//         {
//             temp.push_back(str);
//             RestoreIP(s,ans,temp,curr+1,dots-1);
//             temp.pop_back();
//             RestoreIP(s,ans,temp,curr,dots+1);
//         }
//         else
//         {  
//             curr++;
//             break;
//         }
//     }
// }
// bool leadingzero(int check)
// {
//     while(check>0)
//     {
//         if(check==0)  return true;
//         check=check/10;
//     }
//     return false;
// }
// int main()
// {
//     string s="25525511135";
//     vector<string> ans;
//     vector<string> temp;
//     RestoreIP(s,ans,temp,0,3);
//     for(const auto& ip : ans)
//     {
//         cout<<ip<<endl;
//     }
// }


#include<iostream>
#include<vector>
#include<string>

using namespace std;

void RestoreIP(string s,
               vector<string>& ans,
               vector<string>& temp,
               int curr)
{
    // Base Case
    if(temp.size() == 4)
    {
        if(curr == s.length())
        {
            string ip =
                temp[0] + "." +
                temp[1] + "." +
                temp[2] + "." +
                temp[3];

            ans.push_back(ip);
        }

        return;
    }

    // Try segment lengths 1 to 3
    for(int len = 1; len <= 3; len++)
    {
        if(curr + len > s.length())
            break;

        string part = s.substr(curr, len);

        // Leading zero check
        if(part.length() > 1 && part[0] == '0')
            continue;

        int num = stoi(part);

        if(num <= 255)
        {
            temp.push_back(part);

            RestoreIP(s, ans, temp, curr + len);

            temp.pop_back();
        }
    }
}

 void RestoreIPI(string s,vector<string>& ans,vector<string>& temp,int curr)
    {
        if(temp.size()==4)
        {
            if(curr==s.length())
            {
                string str=temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3];
                ans.push_back(str);
            }
            return;
        }
        for(int len=1;len<=3;len++)
        {
            if(curr+len >s.length()) break;
            string part=s.substr(curr,len);
            if(part[0]=='0' && part.length()>1) continue;
            int check=stoi(part);
            if(check<=255)
            {
                temp.push_back(part);
                RestoreIPI(s,ans,temp,curr+len);
                temp.pop_back();
            }
        }
    }


int main()
{
    string s = "25525511135";

    vector<string> ans;
    vector<string> temp;

   // RestoreIP(s, ans, temp, 0);
    RestoreIPI(s,ans,temp,0);
 
    for(const auto& ip : ans)
    {
        cout << ip << endl;
    }
}