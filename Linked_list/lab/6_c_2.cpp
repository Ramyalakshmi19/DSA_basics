#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* &head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void printList(Node* head) {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void swapValues(Node* &head, int val1, int val2) {
    if (head == NULL || val1 == val2) {
        return;
    }

    Node* prev1 = NULL;
    Node* curr1 = head;
    while (curr1->data != val1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node* prev2 = NULL;
    Node* curr2 = head;
    while (curr2->data != val2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if (curr1 == NULL || curr2 == NULL) {
        return;
    }

    if (prev1 != NULL) {
        prev1->next = curr2;
    }
    else {
        head = curr2;
    }

    if (prev2 != NULL) {
        prev2->next = curr1;
    }
    else {
        head = curr1;
    }

    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

int main() 
{
    int num1,num2;
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    cout<<"List before swapping:";
    printList(head);
    cout<<"Enter two values to swap:\n";
    cout<<"NUMBER-1:";
    cin>>num1;
    cout<<"NUMBER-2:";
    cin>>num2;
    swapValues(head,num1,num2);
    cout<<"After swapping:";
    printList(head);
}