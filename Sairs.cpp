#include<iostream>
using namespace std;
int f(int n)
    {int a=0;
        while(n>1){
            a+=n;
            n--;
        }
    }
int main(){
    int n=5;
    if(n==0){
        cout<<0;
        return 0;
    }
    int stairs[n+1];
    stairs[1]=1;
    stairs[2]=2;
    for(int i=3;i<=n;i++){
        stairs[i]=stairs[i-1]+stairs[i-2];
    }
    cout<<stairs[n];
    return stairs[n];
}