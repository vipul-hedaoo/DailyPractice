#include<iostream>
#include<vector>
#include<string> 
using namespace std;
int numberOfSpecialChars(string word) {

        vector<int> firstUpper(26, -1);
        vector<int> lastLower(26, -1);

        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if(ch >= 'a' && ch <= 'z')
            {
                lastLower[ch - 'a'] = i;
            }
            else
            {
                if(firstUpper[ch - 'A'] == -1)
                {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++)
        {
            if(lastLower[i] != -1 &&
               firstUpper[i] != -1 &&
               lastLower[i] < firstUpper[i])
            {
                count++;
            }
        }

        return count;
    }
int main()
{
  string s1="AbcbDBdD";
// //   vector<int> freq (26,0);
// //   int num=0;
// //   for(char ch: s1)
// //   {
// //     if(ch>=97 && ch<=122 )
// //     {
// //        freq[ch-'a']++;
// //     }
// //     else{
// //         char s=tolower(ch);
// //         if(freq[s-'a']>0)freq[s-'a']=-1;
// //     }
//   }
//   for(int i=0;i<freq.size();i++)
//   {
//     cout<<freq[i]<<" ";
//     if(freq[i]==-1) num++; 
//   }
//   cout<<num;
cout<<numberOfSpecialChars(s1);
}