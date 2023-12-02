#include<iostream>
using namespace std;
int num;
void get_data(int** tri_diag)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if((i==j)||(j==i+1)||(j==i-1))
            {
                cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                cin>>tri_diag[i][j];
            }
            else
                tri_diag[i][j]=0;
        }
    }
}
void display(int** tri_diag)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<tri_diag[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cols in the tridiagonal matrix:";
    cin>>num;
    int** tri_diag=new int*[num];
    for(int i=0;i<num;i++)
    {
        tri_diag[i]=new int[num];
    }
    get_data(tri_diag);
    display(tri_diag);
}
