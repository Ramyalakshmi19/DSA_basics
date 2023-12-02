#include<iostream>
using namespace std;
class queue
{
    public:
    int max_size,count;
    queue(int n)
    {
        max_size=n;
        front=-1;
        rear=-1;
        count=0;
    }
    int *arr=(int*)malloc(max_size-1);
    void isfull()
    {
        if(count==max_size)
        {
            cout<<"Queue is full\n";
        }
        else
        {
            cout<<"Queue is not full\n";
        }
    }
    bool isempty()
    {
        return count;
    }
    void peek()
    {
        cout<<"The first element in the array:"<<arr[front]<<endl;
    }
    int front,rear;
    void enqueue(int value)
    {
        if (count!=max_size)
        {
            if (count == 0)
            {
                rear = 0;
                front = 0;
            }
            arr[rear++] = value;
            count++;
            cout<<"Element is added\n";
        }
        else
        {
            cout<<"Queue is full\n";
        }
    }
    void dequeue()
    {
        if(count!=0)
        {
            cout<<arr[front++]<<"is removed from queue\n";
            count--;

        }
        else
        {
            cout<<"Queue is empty\n";
        }
    }
    void display()
    {
        for(int i=0;i<count;i++)
        {
            cout<<arr[i]<<" ";
        }

    }
};

int main()
{
    int ch=1,n,res;
    int option;
    cout<<"Enter the maximum size:";
    cin>>n;
    queue q1(n);
    while(ch)
    {
        cout<<"------------MENU-------------------";
        cout<<"\n1.Add an element to Queue\n2.Delete an element from Queue\n3.To check if Queue is full\n4.To check if queue is empty\n5.To check the frst element in the queue\n6.Display";
        cout<<"Enter your choice:";
        cin>>option;
        switch(option)
        {
            case 1:
                int data;
                cout<<"Enter the data to be added:";
                cin>>data;
                q1.enqueue(data);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.isfull();
                break;
            case 4:
                res=q1.isempty();
                if(res==0)
                {
                    cout<<"Queue is empty\n";
                }
                else
                {
                    cout<<"Queue is not empty\n";
                }
                break;
            case 5:
                q1.peek();
                break;
            case 6:
                q1.display();
                break;
            default:
                cout<<"Invalid input";
    
    }
        cout<<"---------------------------------------";
        cout<<"\nDo you want to continue?(y/n)";
        cin>>ch;   
    }


    }
