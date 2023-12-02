#include<iostream>
using namespace std;
int num;
void set_data(int** diag)
{
    cout<<"Enter the principal diagonal elements:\n";
    for(int i=0;i<num;i++)
    {
        cin>>diag[i][i];
    }
}
void display(int** diag)
{
    cout<<"Diagonal matrix:\n";
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(i!=j)
                cout<<"0"<<" ";
            else
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
    if((row-1)==(col-1))
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