//Create a linked list with f(x)={5,4,7,8,11,15,16}
//a) Insert f(x)=9
//b) delete f(x8)
#include<iostream>
using namespace std;
struct linked_node
{
    int value;
    linked_node* next;
};
typedef struct linked_node node;
class linked_list
{
    public:
        node* head=NULL;
    void insert(int data)
    {
        node* new_node=(node*)malloc(sizeof(node));
        new_node->value=data;
        if(head==NULL)
        {
            new_node->next=NULL;
        }
        else
        {
            new_node->next=head;
        }
        head=new_node;
    }
    void insert_at_middle(int data,int position)
    {
        node* new_node=(node*)malloc(sizeof(node));
        node* temp=head;
        new_node->value=data;
        for(int i=1;i<=position-2;i++)
        {
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void delete_elem(int pos)
    {
        node* prev=head;
        node* temp=head->next;
        for(int i=1;i<pos-1;i++)
        {
            
            temp=temp->next;
            prev=prev->next;
        }
        (prev->next)=temp->next;
        free(temp);

    }
    void display()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    linked_list l1;
    l1.insert(16);
    l1.insert(15);
    l1.insert(11);
    l1.insert(8);
    l1.insert(7);
    l1.insert(4);
    l1.insert(5);
    cout<<"The linked list is:\n";
    l1.display();
    cout<<"\nAfter inserting 9 at position 5:\n";
    l1.insert_at_middle(9,5);
    l1.display();
    l1.delete_elem(8);
    cout<<"\nAfter deleting the 8th element the linked list is:\n";
    l1.display();
}