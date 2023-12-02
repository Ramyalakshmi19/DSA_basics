#include<iostream> 
using namespace std; 
#define $ NULL
 class node
 {
    public:
    int data; 
    node* right; 
    node* left; 
    node(int val)
    {
    data=val;
     left=NULL; 
     right=NULL;
    }
};
void inOrder(node* root)
{
     if (root != NULL)
     {
        inOrder(root->left);
        cout << root->data <<" "; 
        inOrder(root->right);
     }
}
void postorder(node* root)
{ 
    if (root != NULL)
    {
        postorder(root->left); 
        postorder(root->right); 
        cout << root->data <<" ";
    }
}
void preOrder(node* root)
{
     if (root != NULL)
     {
        cout << root->data <<" "; 
        preOrder(root->left); 
        preOrder(root->right); 
    }
}
node* insertLevelOrder(int arr[],int i, int n)
{
     node *root = NULL;
     if (i < n)
     { 
        if(arr[i]!=NULL)
        {
            root = new node(arr[i]);
            root->left = insertLevelOrder(arr,2 * i + 1, n); 
            root->right = insertLevelOrder(arr,2 * i + 2, n);
        }
}
return root;
}
int main()
{
    int arr[]= {7,2,3,$,5,7,9,$,$,10,12,14,15,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = insertLevelOrder(arr, 0, n);
    cout<<"given array : 7 2 3 $ 5 7 9 $ 10 12 14 15 18 "<<endl; 
    cout<<"Inorder traversal"<<endl;
    inOrder(root);
    cout<<"\npreorder traversal"<<endl; preOrder(root);
    cout<<"\npostorder traversal"<<endl; postorder(root);
    cout<<"\n"<<endl;
}