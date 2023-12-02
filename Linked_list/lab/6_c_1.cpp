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

Node* createCircularList(int n) {
  Node* head = createNode(1);
  Node* curr = head;
  for (int i = 2; i <= n; i++) {
    Node* newNode = createNode(i);
    curr->next = newNode;
    curr = newNode;
  }
  curr->next = head;
  return head;
}

void insertAfter(Node* head, int data, int pos) {
  Node* curr = head;
  for (int i = 0; i < pos; i++) {
    curr = curr->next;
  }
  Node* newNode = createNode(data);
  newNode->next = curr->next;
  curr->next = newNode;
}

void deleteNode(Node* head, int pos) {
  Node* curr = head;
  for (int i = 0; i < pos - 1; i++) {
    curr = curr->next;
  }
  Node* temp = curr->next;
  curr->next = temp->next;
  delete temp;
}

void printList(Node* head) {
  Node* curr = head;
  do {
    cout << curr->data << " ";
    curr = curr->next;
  } while (curr != head);
  cout << endl;
}

int main() {
  cout << "Enter the number of nodes: ";
  int n;
  cin >> n;

  Node* head = createCircularList(n);

  while (true) {
    cout << "Enter 1 to insert, 2 to delete, or 0 to terminate: ";
    int choice;
    cin >> choice;
    if (choice == 0) {
      break;
    } else if (choice == 1) {
      cout << "Enter the data and position to insert: ";
      int data, pos;
      cin >> data >> pos;
      insertAfter(head, data, pos);
      printList(head);
    } else if (choice == 2) {
      cout << "Enter the position to delete: ";
      int pos;
      cin >> pos;
      deleteNode(head, pos);
      printList(head);
    }
  }

  return 0;
}
