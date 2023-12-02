#include<iostream>
using namespace std;
int num;
void get_data(int *arr)
{
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
}
void insert(int* arr,int value,int position)
{
    for(int i=num+1;i>=position;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position-1]=value;
}
void display(int* arr)
{
    for(int i=0;i<num+1;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int insert_value,insert_pos;
    int *ptr_array=new int[num+1];
    cout<<"Enter the number of elements in array:";
    cin>>num;
    cout<<"Enter the elements in the array:";
    get_data(ptr_array);
    cout<<"\nEnter the value to be inserted:";
    cin>>insert_value;
    cout<<"Enter the position to be inserted:";
    cin>>insert_pos;
    insert(ptr_array,insert_value,insert_pos);
    display(ptr_array);


}