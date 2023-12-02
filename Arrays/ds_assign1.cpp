#include<iostream>
using namespace std;
int main()
{
    string s;
    int number,flag=0;
    cout<<"Enter the number of  elements:";
    cin>>number;
    string array[number];
    for(int i=0;i<number;i++)
    {
        cout<<"Enter the element-"<<i+1<<":";
        cin>>array[i];
    }
    cout<<"Enter a string to search:";
    cin>>s;
    for(int i=0;i<number;i++)
    {
        if(array[i]==s)
        {
            cout<<"String found at position "<<i+1;
            flag+=1;
        }
    }
    if(flag==0)
    {
        cout<<"String not found";
    }
}