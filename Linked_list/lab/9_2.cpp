#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
node* create_node(int data)
{
    node* new_node=new node();
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}
node* insert(node* root,int data)
{
    if(root==NULL)
    {
        return create_node(data);
    }
    if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    else
    {
        root->left=insert(root->left,data);
    }
    return root;
}
node* preorder(node* root)
{
    if( root!=NULL)
    {
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    }
}
int main()
{
    node* root=create_node(40);
    insert(root,30);
    insert(root,50);
    insert(root,25);
    insert(root,35);
    insert(root,15);
    insert(root,28);
    insert(root,45);
    insert(root,60);
    insert(root,55);
    insert(root,70);
    preorder(root);

}