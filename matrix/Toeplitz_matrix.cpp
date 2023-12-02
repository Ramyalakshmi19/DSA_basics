#include<iostream>
using namespace std;
int num;
void get_data(int** arr)
{
     for(int i=0;i<num;i++)
     {
        for(int j=0;j<num;j++)
        {
            if(i==0)
            {
               cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
               cin>>arr[i][j]; 
               
            }
        }
     }
}
void set_data()
{
    for(int k=1;k<num;k++)
        arr[k][k]=arr[0][0];
            
}
void display(int** arr)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cols in Toeplitz matrix:";
    cin>>num;
    int** toeplitz=new int*[num];
    for(int i=0;i<num;i++)
    {
        toeplitz[i]=new int[num];
    }
    get_data(toeplitz);
    display(toeplitz);
}