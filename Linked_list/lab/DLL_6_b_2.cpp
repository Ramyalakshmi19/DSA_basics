#include<iostream>
using namespace std;
struct linked_node
{
    int data;
    linked_node* prev;
    linked_node* next;
};
typedef struct linked_node node;
class doubly_linked_list
{
    public:
        node* head=NULL;
        void insert(int n)
        {
            node* new_node=(node*)malloc(sizeof(node));
            new_node->data=n;
            if(head==NULL)
            {
                new_node->prev=NULL;
                new_node->next=NULL;
                head=new_node;
            }
            else
            {
                new_node->prev=NULL;
                new_node->next=head;
                head->prev=new_node;
                head=new_node;
            }
        }
        void sort()
        {
            node* current=NULL;
            node* index=NULL;
            int temp;
            if(head==NULL)
            {
                cout<<"List is empty\n";
            }
            else{
            for(current=head;current->next!=NULL;current=current->next)
            {
                for(index=current->next;index!=NULL;index=index->next)
                {
                    if(current->data>index->data)
                    {
                        temp=current->data;
                        current->data=index->data;
                        index->data=temp;

                    }
                }
            }
            }

        }
        void display()
        {
            node* temp=head;
            if(head==NULL)
            {
                cout<<"List is empty\n";
            }
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

};
int main()
{
    doubly_linked_list list1;
    int n,num;
    cout<<"Enter the number of nodes:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number "<<i+1<<":";
        cin>>num;
        list1.insert(num);
    }
    cout<<"----------------------------------------\n";
    cout<<"List before sorting\n";
    list1.display();
    list1.sort();
    cout<<"\nList after sorting\n";
    list1.display();
}