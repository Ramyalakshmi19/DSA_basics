#include<iostream>
using namespace std;
#define $ NULL
struct node
{
    int data;
    node* left;
    node* right;
};
typedef struct node node;
class tree
{
    public:
        node* root=NULL;
        void getdata()
        {
            int arr[14]= {7,2,3,$,5,7,9,$,$,10,12,14,15,18};
            int n=sizeof(arr)/sizeof(arr[0]);
            for(int i=0;i<n;i++)
            {
                root=insert(root,arr[i]);
            }
        }
        node* createnode(int val)
        {
                node* temp=(node*)malloc(sizeof(node));
                temp->data=val;
                temp->left=temp->right=NULL;
                return temp;
        }
    
        node* insert(node* node, int val)
        {
            if(node==NULL)
            {
                return createnode(val);
            }
            if(val<node->data)
            {
                node->left=insert(node->left,val);
            }
            else if(val>=node->data)
            {
                node->right=insert(node->right,val);
            }
            return node;
        }
        void preorder(node* root)
        {
            if(root!=NULL)
            {
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void postorder(node* root)
        {
            if(root!=NULL)
            {
                preorder(root->left);
                cout<<root->data<<" ";
                preorder(root->right);
            }
        }
};
int main()
{
    tree t1;
    t1.getdata();
}