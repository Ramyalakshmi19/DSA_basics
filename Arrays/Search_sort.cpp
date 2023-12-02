#include<iostream>
using namespace std;
class Array
{
    public:
        void get_data(int a[],int n)
        {
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        }
        void search_elem(int a[],int n,int s)
        {
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==s)
                {
                    flag=1;
                    cout<<s<<" is found at the index "<<i<<endl;
                }
                else
                {
                    continue;
                }
            }
            if(flag==0)
            {
                cout<<"Element not found"<<endl;
            }
        }
        void sort_elem(int a[],int n)
        {
            int temp;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(a[i]>a[j])
                    {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            display(a,n);
        }
        void display(int a[],int n)
        {
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
};
int main()
{
    int num,option,search_num,choice=1;
    Array Arr1;
    cout<<"Enter the num of elements in an array:";
    cin>>num;
    int arr[num];
    while(choice==1)
    {
        cout<<"1.Enter array elements\n2.Search an element\n3.Sort the data\n";
        cout<<"Enter your choice:";
        cin>>option;
        switch(option)
        {
        case 1:
        {
            Arr1.get_data(arr,num);
            break;
        }
        case 2:
        {
            cout<<"Enter the element to search:";
            cin>>search_num;
            Arr1.search_elem(arr,num,search_num);
            break;
        }
        case 3:
        {
            Arr1.sort_elem(arr,num);
            break;
        }
        default:
            cout<<"Invalid input";
        }
        cout<<"Do you want to continue?(1/0)";
        cin>>choice;
        cout<<"----------------------------\n";
    }

    


}