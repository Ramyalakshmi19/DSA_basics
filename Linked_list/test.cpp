#include<iostream>
using namespace std;
struct student_node
{
    int num;
    string name;
    int marks[3];
    int average_mark;
    student_node* next;
};
typedef struct student_node node;
class Student
{
        public:
            int total=0;
            node* head=NULL;
        void create()
        {
            node *new_node = (node *)malloc(sizeof(node));
            for(int i=0;i<3;i++)
            {
            cout << "---------------STUDENT------------\n";
            cout << "Enter the Reg num:";
            cin >> new_node->num;
            cout << "Enter the Name:";
            cin >> new_node->name;
            for (int i = 0; i < 3; i++)
            {
            cout << "Enter the mark-" << (i + 1) << ":";
            cin >> new_node->marks[i];
            total += (new_node->marks[i]);
            }
            new_node->average_mark = (total / 3);
            cout<<new_node->average_mark;
            if (head == NULL)
            {
                head = new_node;
                new_node->next = NULL;
                cout << "First node inserted";
            }
            else
            {
                new_node->next = head;
                head = new_node;
                cout << "Node inserted";
            } 
            display();
            }

        }
        void display()
        {
        node* temp;
        while(temp!=NULL)
        {
            cout<<"-----------------------STUDENT DETAILS----------------------\n";
            cout<<"REGISTER NUMBER:"<<temp->num;
            cout<<"NAME:"<<temp->name;
            cout<<"MARK-1:"<<temp->marks[0];
            cout<<"MARK-2:"<<temp->marks[1];
            cout<<"MARK-3:"<<temp->marks[2];
            cout<<"AVERAGE MARK:"<<temp->average_mark;
            cout<<"-------------------------------------------------------------\n";
            temp=temp->next;
        }
    }
};
int main()
{
    Student s1;
    s1.create();
}
