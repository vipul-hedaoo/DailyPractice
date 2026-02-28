  #include <iostream>
  using namespace std;
  int strStr(string haystack, string needle) {
    //two poniter
    int first=0,second=0;
    for(first,second;first<haystack.length() && second<needle.length();first++)
    {
        if(haystack.at(first)==needle.at(second))
        {
            ++second;
        }
    }
    first--;
    second--;
    if(second!=(needle.length()-1))
    {
      return -1;
    }
    return first-second;
        
    }

    int strStr1(string haystack, string needle) {
    
    if (needle.length() == 0) return 0;

    for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        
        int j = 0;
        
        // check substring starting from i
        while (j < needle.length() && 
               haystack[i + j] == needle[j]) {
            j++;
        }
        
        // if full match found
        if (j == needle.length()) {
            return i;
        }
    }
    
    return -1;
}
int main()
{
    string first="sadooooo",second="sad";
    cout<<strStr1(first,second);

}