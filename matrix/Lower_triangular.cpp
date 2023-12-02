#include<iostream>
using namespace std;
int num;
void get_data(int** lower_tri)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(i<j)
            {
                // cout<<"Element in row "<<i+1<<" and column "<<j+1<<": 0\n";
                lower_tri[i][j]=0;
            }
            else
            {
                cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                cin>>lower_tri[i][j];
            }
                
        }
    }
}
void display(int** lower_tri)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<lower_tri[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cols of the lower triangular matrix:";
    cin>>num;
    int** lower_tri=new int*[num];
    for(int i=0;i<num;i++)
    {
        lower_tri[i]=new int[num];
    }
    get_data(lower_tri);
    display(lower_tri);
}