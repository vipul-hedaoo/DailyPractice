#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
 bool asteroidsDestroyed(int planet1, vector<int>& astroids) {
    long long planet=planet1;
    sort(astroids.begin(),astroids.end());
    stack<int> st;
    for(int i=0;i<astroids.size();i++)
    {
      if(planet<astroids[i]) return false;
      planet+=astroids[i];
    }
    return true;
    }
int main()
{
    vector<int> astroid={4,9,23,4};
    int planet=5;
    cout<<asteroidsDestroyed(planet,astroid);
}