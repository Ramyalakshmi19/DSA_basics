#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree() { root = nullptr; }
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (data < current->data)
                {
                    if (current->left == nullptr)
                    {
                        current->left = newNode;
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = newNode;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }
    int kthSmallest(Node *node, int k, int &count)
    {
        if (node == nullptr)
        {
            return -1;
        }
        int left = kthSmallest(node->left, k, count);
        if (left != -1)
        {
            return left;
        }
        count++;
        if (count == k)
        {
            return node->data;
        }
        int right = kthSmallest(node->right, k, count);
        return right;
    }
    int kthLargest(Node *node, int k, int &count)
    {
        if (node == nullptr)
        {
            return -1;
        }
        int right = kthLargest(node->right, k, count);
        if (right != -1)
        {
            return right;
        }
        count++;
        if (count == k)
        {
            return node->data;
        }
        int left = kthLargest(node->left, k, count);
        return left;
    }
};

int main()
{
    BinarySearchTree bst;
    int data;
    cout << "Enter numbers to insert into the binary search tree (-1 to stop):"<<endl;
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        bst.insert(data);
    }
    int k;
    cout << "Enter a value for k: ";
    cin >> k;
    int count = 0;
    int kthSmallest = bst.kthSmallest(bst.root, k, count);
    if (kthSmallest != -1)
    {
        cout << "The kth smallest element is: " << kthSmallest << std::endl;
    }
    else
    {
        cout << "There are less than k elements in BST:";
    }
    count = 0;
    int kthLargest = bst.kthLargest(bst.root, k, count);
    if (kthLargest != -1)
    {
        cout << "The kth Largest element is: " << kthLargest << std::endl;
    }
    else
    {
        cout << "There are less than k elements in BST:";
    }
}