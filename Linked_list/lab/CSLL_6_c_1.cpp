#include<iostream>
using namespace std;
struct circular_list_node
{
    int data;
    circular_list_node* next;
};
typedef struct circular_list_node node;
class circular_list
{
    public:
        node* head=NULL;
        void insert_at_beginning(int data)
        {
            node* ptr1 = (node*) malloc(sizeof(node));
            node *temp = head;
    ptr1->data = data;
    ptr1->next = head;
    if (head!= NULL)
    {
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; 
 
    head = ptr1;
        }
        void display()
        {
            if(head==NULL)
            {
                cout<<"List is empty\n";
            }
            else
            {
                node* temp=head;
                do
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }while(temp!=head);
                
            }

        }
};
int main()
{
    circular_list list1;
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
                list1.insert_at_beginning(num);
                break;
            // case 2:
            //     cout<<"Enter a number to insert:";
            //     cin>>num;
            //     list1.insert_at_end(num);
            //     break;
            // case 3:
 
            //     cout<<"Enter a number to insert:";
            //     cin>>num;
            //     cout<<"Enter the position:";
            //     cin>>pos;
            //     list1.insert_at_pos(num,pos);
            //     break;
            // case 4:
            //     list1.delete_at_beginning();
            //     break;
            // case 5:
            //     list1.delete_at_end();
            //     break;
            // case 6:
            //     cout<<"Enter a position to delete:";
            //     cin>>pos;
            //     list1.delete_at_pos(pos);
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