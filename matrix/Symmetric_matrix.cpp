#include<iostream>
using namespace std;
int num;
void get_data(int** symm)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if((i==j)||(i>j))
            {
                cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                cin>>symm[i][j];
            }
        }
    }
}
void display(int** symm)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if((i==j)||(i>j))
                cout<<symm[i][j]<<" ";
            else
                cout<<symm[j][i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cold in symmetric matrix:";
    cin>>num;
    int** symm=new int*[num];
    for(int i=0;i<num;i++)
    {
        symm[i]=new int[num];
    }
    get_data(symm);
    display(symm);
}