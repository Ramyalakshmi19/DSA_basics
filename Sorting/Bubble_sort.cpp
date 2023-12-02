#include<iostream>
using namespace std;
class bubble_Sort
{
    private:
        int num;
        int* array;
    public:
        bubble_Sort(int* arr,int n)
        {
            num=n;
            array=new int[num];
            array=arr;
            for(int i=0;i<num;i++)
            {
                cout<<"Enter the element "<<i+1<<":";
                cin>>array[i];
            }
            cout<<"The entered array:";
            for(int i=0;i<num;i++)
            {
                cout<<array[i]<<" ";
            }
            
        }
        void sort()
        {
            int temp;
            for(int i=0;i<num-1;i++)
            {
                for(int j=0;j<num-1;i++)
                {
                    if(array[j]>array[j+1])
                    {
                        temp=array[i];
                        array[i]=array[j];
                        array[j]=temp;
                    }
                }
            }
            display();
        }

        void display()
        {
            cout<<"The sorted array:";
            for(int i=0;i<num;i++)
            {
                cout<<array[i]<<" ";
            }
        }
};
int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int* arr=new int[n];
    bubble_Sort Array(arr,n);
    Array.sort();
}