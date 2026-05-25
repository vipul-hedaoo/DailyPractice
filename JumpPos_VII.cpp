#include<iostream>
#include<string>
using namespace std;
bool jumpPos(string s,int min,int max,int ind)
    {
        if(ind>=s.length()) return false;
        if(ind==s.length()-1) return true;
        while(ind<s.length())
        {
            jumpPos(s,min,max,ind+max);
            //ind=ind-max;
            jumpPos(s,min,max,ind+min);
        }
    }
int main()
{
  string s="100100100";
  int min=2;
  int max=3;
  if(s.length()<min) cout<<"false";
  cout<<jumpPos(s,min,max,0);
}