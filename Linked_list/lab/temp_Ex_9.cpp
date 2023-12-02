#include <iostream>

using namespace std;

// Node class for a binary search tree
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

// BinarySearchTree class
class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    // Inserts a value into the binary search tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Determines the kth smallest element in the binary search tree
    int kthSmallest(int k) {
        int count = 0;
        return kthSmallest(root, k, count);
    }

    // Determines the kth largest element in the binary search tree
    int kthLargest(int k) {
        int count = 0;
        return kthLargest(root, k, count);
    }

private:
    // Recursive helper function for inserting a value into the binary search tree
    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Recursive helper function for finding the kth smallest element in the binary search tree
    int kthSmallest(Node* node, int k, int& count) {
        if (node == NULL) {
            return -1;
        }
        int left = kthSmallest(node->left, k, count);
        if (left != -1) {
            return left;
        }
        count++;
        if (count == k) {
            return node->value;
        }
        return kthSmallest(node->right, k, count);
    }

    // Recursive helper function for finding the kth largest element in the binary search tree
    int kthLargest(Node* node, int k, int& count) {
        if (node == NULL) {
            return -1;
        }
        int right = kthLargest(node->right, k, count);
        if (right != -1) {
            return right;
        }
        count++;
        if (count == k) {
            return node->value;
        }
        return kthLargest(node->left, k, count);
    }
};

int main() {
    BinarySearchTree tree;

    // Insert values into the binary search tree
    cout << "Enter values to be inserted into the binary search tree (-1 to stop):" << endl;
    int value;
    cin >> value;
    while (value != -1) {
        tree.insert(value);
    }
      int k;
  std::cout << "Enter a value for k: ";
  std::cin >> k; 
