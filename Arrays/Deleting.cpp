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
int delete_element(int* arr,int value)
{
    int flag=0;
    for(int i=0;i<num;i++)
    {
        if(arr[i]==value)
        {
            return i+1;
            flag+=1;
        }
    }
    if(flag==0)
        cout<<"Element not found";
}
void delete_elempos(int* arr,int position)
{
    for(int i=position;i<num;i++)
    {
        arr[i-1]=arr[i];
    }
    num=num-1;
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
    int choice,delete_position,delete_value;
    cout<<"Enter the number of elements in the array:";
    cin>>num;
    int* ptr_array=new int[num];
    get_data(ptr_array);
    cout<<"Do you want to input\n1.Position of the element\n2.The element\n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter the position of the element to be deleted:";
        cin>>delete_position;
        delete_elempos(ptr_array,delete_position);
    }
    else if(choice==2)
    {
        cout<<"Enter the element to be deleted:";
        cin>>delete_value;
        delete_position=delete_element(ptr_array,delete_value);
        delete_elempos(ptr_array,delete_position);
    }
    else
        cout<<"INVALID INPUT";
    display(ptr_array);

}