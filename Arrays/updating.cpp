#include<iostream>
using namespace std;
int num;
void get_data(int* arr)
{
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
}
void update(int* arr,int ch)
{
    int old_value,new_value,position;
    if(ch==1)
    {
        cout<<"Enter the element to be updated:";
        cin>>old_value;
        cout<<"Enter the new value";
        cin>>new_value;
        for(int i=0;i<num;i++)
        {
            if(arr[i]==old_value)
                arr[i]=new_value;
                
        }
    }
    else if(ch==2)
    {
        cout<<"Enter the position to be updated:";
        cin>>position;
        cout<<"Enter the new value:";
        cin>>new_value;
        arr[position-1]=new_value;
    }
    else
        cout<<"INVALID INPUT";
}
void display(int* arr)
{
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int choice;
    cout<<"Enter the number of elements in the array:";
    cin>>num;
    int* ptr_array=new int[num];
    cout<<"Enter the elements of array:";
    get_data(ptr_array);
    cout<<"Do you want to input\n1.The element to be updated\n2.The postion to be updated\n";
    cin>>choice;
    update(ptr_array,choice);
    display(ptr_array);
}
