#include <iostream>
using namespace std;
struct number
{
    int num;
    number* next;
};
typedef struct number node;
class linked_list
{
    public:
        static int count;
        node* head=NULL;
        void insert(int digit)
        {
            node* new_node=(node*)malloc(sizeof(node));
            new_node->num=digit;
            if(head==NULL)
            {
                head=new_node;
                new_node->next=NULL;
            }
            else
            {
                new_node->next=head;
                head=new_node;
            }
        }
        void display()
        {
            node* temp=head;
            
            while(temp!=NULL)
            {
                cout<<temp->num<<" ";
                temp=temp->next;
                count++;
            }
            cout<<"\nThe total number of elements in linked list:"<<count;
        }
        void search(int n)
        {
            int i=0,flag=0;
            node* temp=head;
            while(temp!=NULL)
            {
            if(temp->num==n)
            {
                flag+=1;
                cout<<"Element is found at index "<<i;
            }
            else
            {
                i++;
            }
                temp=temp->next;
            }
            if(flag==0)
            {
                cout<<"Element not found\n";
            }

        }
        void reverse()
        {
            node* current=head;
            node* prev;
            node* next;
            while(current!=NULL)
            {
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            head=prev;
            display();
        }
       
};
int linked_list::count=0;
int main()
{
    linked_list list1;
    int num,search_elem;
    cout<<"Enter a number:";
    cin>>num;
    while(num)
    {
        int last_digit=num%10;
        num/=10;
        list1.insert(last_digit);
    }
    list1.display();
    cout<<"\n-------------------------------\n";
    cout<<"ENTER AN ELEMENT TO SEARCH:";
    cin>>search_elem;
    list1.search(search_elem);
    cout<<"\n-------REVERSED LINKED LIST--------\n";
    list1.reverse();
}