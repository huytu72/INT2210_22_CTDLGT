#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    // Insert a node at position p with value x
    void insert(int p, int x) {
        Node* newNode = makeNode(x);
        if (p == 0 || head == NULL) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int pos = 0;
            while (pos < p - 1 && current->next != NULL) {
                current = current->next;
                pos++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Delete a node at position p
    void remove(int p) {
        if (head == NULL) {
            return; // List is empty, nothing to delete
        }
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int pos = 0;
            while (pos < p - 1 && current->next != NULL) {
                current = current->next;
                pos++;
            }
            if (current->next == NULL) {
                return; // Position p is out of bounds
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Print the linked list
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList myList;

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            myList.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            myList.remove(p);
        }
    }

    myList.print();

    return 0;
}
