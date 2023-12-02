#include<iostream>
#include<stack>
class exp
{
    public:
        int prec(char c)
        {
            if(c=='^')
                return 3;
            else if(c=="+"||c=='-')
                return 1;
            else if(c=='*'||c=='/')
                return 2;
            else
                return -1;
        }
        void convert(string s)
        {
            stack
            
        }
}
int main()
{
    string exp;
    cout<<"Enter the expression:";
    cin>>exp;
}