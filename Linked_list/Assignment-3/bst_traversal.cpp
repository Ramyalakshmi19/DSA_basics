#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
class tree
{
    public:
        node* root=NULL;
        void insert(int data)
        {
            node* new_node=new node(data);
            if(root==NULL)
            {
                root=new_node;
            }
            else
            {
                node* current=root;
                while(true)
                {
                if(data<current->data)
                {
                    if(current->left==NULL)
                    {
                        current->left=new_node;
                        break;
                    }
                    else
                    {
                        current=current->left;
                    }
                }
                else
                {
                    if(current->right==NULL)
                    {
                        current->right=new_node;
                        break;
                    }
                    else
                    {
                        current=current->right;
                    }
                }
                }
            }
        }
        void preorder(node* temp)
        {
            if(temp!=NULL)
            {
                cout<<temp->data;
                preorder(temp->left);
                preorder(temp->right);
            }
        }
        void inorder(node* temp)
        {
            if(temp!=NULL)
            {
                inorder(temp->left);
                cout<<temp->data<<" ";
                inorder(temp->right);
            }
        }
        
};
int main()
{
    int n,num;
    tree bst;
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the num-"<<i+1<<":";
        cin>>num;
        bst.insert(num);

    }
    bst.inorder(bst.root);
}