#include<iostream>
using namespace std;
struct node_list
{
    int data;
    node_list* prev;
    node_list* next;
};
typedef struct node_list node;
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
                cout<<"The node is inserted\n";
            }
            else
            {
                new_node->prev=NULL;
                new_node->next=head;
                head->prev=new_node;
                head=new_node;
                cout<<"The node is inserted\n";
            }

        }
        void insert_at_end(int n)
        {
            node* new_node=(node*)malloc(sizeof(node));
            new_node->data=n;
            node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            new_node->next=NULL;
            temp->next=new_node;
            new_node->prev=temp;
        }
        void insert_at_pos(int n,int pos)
        {
            node* new_node=(node*)malloc(sizeof(node));
            new_node->data=n;
            node* temp=head;
            for(int i=0;i<pos-2;i++)
            {
                temp=temp->next;
            }
            new_node->prev=temp;
            new_node->next=temp->next;
            temp->next=new_node;
            (temp->next)->prev=new_node;
            cout<<n<<" is inserted at position "<<pos<<endl;
        }
        void delete_at_beginning()
        {
            node* temp=head;
            if(head==NULL)
            {
                cout<<"List is empty\n";
            }
            else if(head->next==NULL)
            {
                free(temp);
                cout<<"The only element is deleted\n";
            }
            else{
                head=temp->next;
                head->prev=NULL;
                free(temp);
            }
        }
        void delete_at_end()
        {
                node* new_node=(node*)malloc(sizeof(node));
                node* temp=head;
                if(head==NULL)
                {
                    cout<<"List is empty\n";
                }
                else if(head->next==NULL)
                {
                    head=NULL;
                    free(temp);
                    cout<<"The only element is deleted\n";
                }
                else
                {
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    (temp->prev)->next=NULL;
                    free(temp);
                }
 
                cout<<"The last node is deleted\n";
        }
        void delete_at_pos(int pos)
        {
            node* temp=head;
            if(head==NULL)
            {
                cout<<"List is empty\n";
            }
            else
            {
                for(int i=1;i<pos;i++)
                {
                    temp=temp->next;
                }
                (temp->next)->prev=temp->prev;
                (temp->prev)->next=temp->next;
                free(temp);
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
    int ch=1,option,num,pos;
    while(ch==1)
    {
        cout<<"\n-------------------MENU----------------------\n";
        cout<<"1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Delete at beginning\n5.Delete at end\n6.Delete at specified position\n7.Traverse\n";
        cout<<"-----------------------------------------------\n";
        cout<<"Enter your option:";
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter a number to insert:";
                cin>>num;
                list1.insert(num);
                break;
            case 2:
                cout<<"Enter a number to insert:";
                cin>>num;
                list1.insert_at_end(num);
                break;
            case 3:
 
                cout<<"Enter a number to insert:";
                cin>>num;
                cout<<"Enter the position:";
                cin>>pos;
                list1.insert_at_pos(num,pos);
                break;
            case 4:
                list1.delete_at_beginning();
                break;
            case 5:
                list1.delete_at_end();
                break;
            case 6:
                cout<<"Enter a position to delete:";
                cin>>pos;
                list1.delete_at_pos(pos);
            case 7:
                list1.display();
                break;
            default:
                cout<<"Invalid input\n";
            
                
        }
        cout<<"Do you want to continue(1/0)?";
        cin>>ch;
    }
}