#include<iostream>
using namespace std;
struct student
{
    int num,mark1,mark2,mark3;
    string name;
    float average;
    student* next;

};
typedef struct student node;
class list
{
    public:
        int reg,m1,m2,m3;
        string n;
        float avg=0;
        node* head=NULL;
        void insert()
        {
            cout<<"----------------STUDENT-------------------\n";
            cout<<"REFISTER NUM:";
            cin>>reg;
            cout<<"NAME:";
            cin>>n;
            cout<<"MARK-1:";
            cin>>m1;
            cout<<"MARK-2:";
            cin>>m2;
            cout<<"MARK-3:";
            cin>>m3;
            avg=(m1+m2+m3)/3;
            node* new_node=(node*)malloc(sizeof(node));
            new_node->name=n;
            new_node->num=reg;
            new_node->mark1=m1;
            new_node->mark2=m2;
            new_node->mark3=m3;
            new_node->average=(m1+m2+m3)/3;
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
                cout<<"----------------STUDENT--------------\n";
                cout<<"NAME:"<<temp->name<<endl;
                cout<<"REGISTER NUMBER:"<<temp->num<<endl;
                cout<<"MARK-1:"<<temp->mark1<<endl;
                cout<<"MARK-2:"<<temp->mark2<<endl;
                cout<<"MARK-3:"<<temp->mark3<<endl;
                cout<<"AVERAGE:"<<temp->average<<endl;
                cout<<"------------------------------------\n";
                temp=temp->next;
            }
        }
        void update()
        {
            int flag=0;
            node* temp=head;
            cout<<"Enter the register number:";
            cin>>reg;
            cout<<"\nEnter the marks to be updated:";
            cout<<"\nMARK-1:";
            cin>>m1;
            cout<<"\nMARK-2:";
            cin>>m2;
            cout<<"\nMARK-3:";
            cin>>m3;
            if(temp==NULL)
            {
                cout<<"The list is empty\n";
            }
            while(temp!=NULL)
            {
                if(temp->num==reg)
                {
                    flag+=1;
                    temp->mark1=m1;
                    temp->mark2=m2;
                    temp->mark3=m3;
                    temp->average=(m1+m2+m3)/3;
                    cout<<"The marks are updated successfully";
                }
                temp=temp->next;
            }
            if(flag==0)
            {
                cout<<"Invalid Register number";
            }

        }
        void search()
        {
            int flag=0;
            node* temp=head;
            while(temp!=NULL)
            {
                if(temp->num==reg)
                {
                flag+=1;
                cout<<"NAME:"<<temp->name<<endl;
                cout<<"REGISTER NUMBER:"<<temp->num<<endl;
                cout<<"MARK-1:"<<temp->mark1<<endl;
                cout<<"MARK-2:"<<temp->mark2<<endl;
                cout<<"MARK-3:"<<temp->mark3<<endl;
                cout<<"AVERAGE:"<<temp->average<<endl;
                cout<<"------------------------------------\n";
                break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(flag==0)
            {
                cout<<"Invalid input\n";
            }
        }
        

};
int main()
{
    int ch=1,option;
    list l1;
    while(ch==1)
    {
        cout<<"----------------MENU-----------------\n";
        cout<<"1.Insert\n2.Update\n3.Delete\n4.Display\n5.Exit\n";
        cin>>option;
        switch(option)
        {
            case 1:
                l1.insert();
                break;
            case 2:
                l1.update();
                break;
            case 3:
                l1.search();
                break;
            case 4:
                l1.display();
                break;
            case 5:
                break;
            default:
                cout<<"Invalid input";
        }
        cout<<"Do you want to continue(1/0)?";
        cin>>option;

    }
}