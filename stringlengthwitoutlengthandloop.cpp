# include <iostream>
using namespace std;
string str="vipul";
int recur(int len,char *a)
{
    if(*a=='\0')
     {
        return len;
     }
     return recur(len+1,a+1);
}
int main()
{
 int len=0;
 char*a=&str[0];
 cout<<recur(len,a);
 
}