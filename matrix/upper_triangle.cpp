#include<iostream>
using namespace std;
int num;
void get_data(int** upper_tri)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(i>j)
            {
                // cout<<"Element in row "<<i+1<<" and column "<<j+1<<": 0\n";
                upper_tri[i][j]=0;
            }
            else
            {
                cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                cin>>upper_tri[i][j];
            }
                
        }
    }
}
void display(int** upper_tri)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<upper_tri[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cols of the lower triangular matrix:";
    cin>>num;
    int** upper_tri=new int*[num];
    for(int i=0;i<num;i++)
    {
        upper_tri[i]=new int[num];
    }
    get_data(upper_tri);
    display(upper_tri);
}