#include<iostream>
using namespace std;
int num;
void set_data(int** diag)
{
    int a=0,b=num-1;
    cout<<"Enter the anti-principal diagonal elements:\n";
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if((i==a)&&(j==b))
            {
                cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                cin>>diag[i][j];
            }
            else
                diag[i][j]=0;

        }
        a+=1;
        b-=1;
    }
}
void display(int** diag)
{
    cout<<"Diagonal matrix:\n";
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
                cout<<diag[i][j]<<" ";
        }
        cout<<endl;
    }
}
void find(int** diag)
{
    int row,col;
    cout<<"To identify the element in given position:\n";
    cout<<"Enter the row of the element:";
    cin>>row;
    cout<<"Enter the col of the element:";
    cin>>col;
    if(diag[row-1][col-1]!=0)
        cout<<"It is a  Non-Zero element with value "<<diag[row-1][col-1];
    else
        cout<<"It is a Zero element";
}
int main()
{
    cout<<"Enter the number of rows/cols in a diagonal matrix:";
    cin>>num;
    int** diag=new int*[num];
    for(int i=0;i<num;i++)
    {
        diag[i]=new int[num];
    }
    set_data(diag);
    display(diag);
    find(diag);

    


}