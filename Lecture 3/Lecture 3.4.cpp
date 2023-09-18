#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation to insert a number at the tail of the queue
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue operation to remove the element at the head of the queue
    void dequeue() {
        if (front == nullptr) {
            return; // Queue is empty, nothing to dequeue
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr; // Queue is empty after dequeue
        }
    }

    // Function to display the resulting queue
    void display() {
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    Queue myQueue;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;
        if (operation == "enqueue") {
            int x;
            std::cin >> x;
            myQueue.enqueue(x);
        } else if (operation == "dequeue") {
            myQueue.dequeue();
        }
    }

    myQueue.display();

    return 0;
}
