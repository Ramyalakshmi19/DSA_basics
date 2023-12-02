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
    void insert_at_beginning(int data)
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
    void insert_at_end(int val)
    {
        node* new_node=(node*)malloc(sizeof(node));
        new_node->value=val;
        node* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                temp=new_node;
                new_node=NULL;
            }
        }

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
    int ch=1,user_choice;
    linked_list list_1;
    while(ch==1)
    {
        cout << "--------------------MENU--------------------\n";
        cout<<"1.Insert\n2.Delete\n3.Display\n";
        cout<<"Enter your choice:\n";
        cin>>user_choice;
        switch(user_choice)
        {
        case 1:
        {
            int insert_value;
            int option;
            cout << "--------------------SUB-MENU--------------------\n";
            cout << "1.Insert at beginning\n2.Insert at position\n3.Insert at end\n";
            cout<<"Enter your choice:";
            cin >> option;
            cout << "ENTER A VALUE TO INSERT:";
            cin >> insert_value;
            switch (option)
            {
            case 1:
                list_1.insert_at_beginning(insert_value);
                break;
            case 2:
                int pos;
                cout<<"Enter a position:";
                cin>>pos;
                list_1.insert_at_middle(insert_value,pos);
            case 3:
                list_1.insert_at_end(insert_value);
                break;
            }
            

            break;
        }
        case 3:
            list_1.display();
            break;
        }
       
        cout<<"\nDo you want to continue(1/0)?";
        cin>>ch;
    }
    
}