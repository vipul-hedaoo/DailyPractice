# include<iostream>
using namespace std;
int main()
{
    int age=0,experiencce=0;
    cout<<"Enter age here :-"<<endl;
    cin>>age;
    cout<<"Enter the experience :-"<<endl;
    cin>>experiencce;
    if(age>=21 && experiencce>=1)
    {
        cout<<"Eligble";
    }
    else{
        cout<<"Not Eligble";
    }
}