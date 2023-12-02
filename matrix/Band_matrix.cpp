#include<iostream>
#include<cstdlib>
using namespace std;
int num;
void get_data(int** band)
{
    int n;
    cout<<"Enter the number of diagonals you want to input(except principal diag):";
    cin>>n;
    if(n%2!=0)
        cout<<"Invalid input. Enter an even number";
    else
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(abs((j-i))<=(n/2)||(i==j))
                {
                    cout<<"Element in row "<<i+1<<" and column "<<j+1<<": ";
                    cin>>band[i][j];
                }
                else
                    band[i][j]=0;
            }
        }
    }

}
void display(int** band)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<band[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the number of rows/cols in band matrix:";
    cin>>num;
    int** band=new int*[num];
    for(int i=0;i<num;i++)
    {
        band[i]=new int[num];
    }
    get_data(band);
    display(band);
}