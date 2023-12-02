#include<iostream>
using namespace std;
class stack_using_Array
{
    public:
        int stack[100];
        int top=-1;
        void push(int data)
        {
                top+=1;
                stack[top]=data;
        }
        void pop()
        {
            top-=1;
        }
        void display()
        {
            int i=top;
            while(i>-1)
            {
                cout<<stack[i]<<" ";
                i--;
                
            }
        }
};
int main()
{
    stack_using_Array s1;
    s1.push(19);
    s1.push(17);
    s1.push(15);
    s1.push(13);
    s1.push(11);
    s1.push(7);
    cout<<"The stack is:\n";
    s1.display();
    s1.push(22);
    s1.push(20);
    cout<<"\nThe stack after pushing 20 and 22:\n";
    s1.display();
    for(int i=0;i<2;i++)
    {
        s1.pop();
    }
    cout<<"\nThe stack after pulling 2 elements:\n";
    s1.display();
}