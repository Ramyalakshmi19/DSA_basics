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
            }
        }
       
};
int main()
{
    linked_list list1;
    int num;
    cout<<"Enter a number:";
    cin>>num;
    while(num)
    {
        int last_digit=num%10;
        num/=10;
        list1.insert(last_digit);
    }
    list1.display();
}