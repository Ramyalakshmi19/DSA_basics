#include<iostream>
using namespace std;
struct queue_node
{
    int data;
    queue_node* next;
};
typedef queue_node node;
class queue
{
    public:
        node* front=NULL;
        node* rear=NULL;
        void enqueue(int val)
        {
            node* new_node=(node*)malloc(sizeof(node));
            new_node->data=val;
            new_node->next=NULL;
            if(front==NULL)
            {
                front=rear=new_node;
            }
            else
            {
                rear->next=new_node;
                rear=new_node;
            }
        }
        void dequeue()
        {
            if(front==NULL)
            {
                cout<<"Queue is empty\n";
            }
            else
            {
                node* temp=front;
                front=front->next;
                cout<<"The element "<<temp->data<<" is deleted\n";
                free(temp);
            }

        }
        bool isempty()
        {
            if(front==NULL)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void peek()
        {
            if(!isempty())
            {
                cout<<"The first element in the queue is "<<front->data<<endl;
            }
        }
        void display()
        {
            node* temp=front;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};
int main()
{
    int ch=1,res;
    int option;
    queue q1;
    while(ch)
    {
        cout<<"\n------------MENU-------------------";
        cout<<"\n1.Add an element to Queue\n2.Delete an element from Queue\n3.To check if queue is empty\n4.To check the frst element in the queue\n5.Display\n";
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
                res=q1.isempty();
                if(res==1)
                {
                    cout<<"Queue is empty\n";
                }
                else
                {
                    cout<<"Queue is not empty\n";
                }
                break;
            case 4:
                q1.peek();
                break;
            case 5:
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