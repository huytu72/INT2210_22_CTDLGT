#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push operation to insert a number to the top of the stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation to remove the element at the top of the stack
    void pop() {
        if (top == nullptr) {
            return; // Stack is empty, nothing to pop
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to display the resulting stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    Stack myStack;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;
        if (operation == "push") {
            int x;
            std::cin >> x;
            myStack.push(x);
        } else if (operation == "pop") {
            myStack.pop();
        }
    }

    myStack.display();

    return 0;
}
