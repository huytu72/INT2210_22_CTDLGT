#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a node at the end of the doubly linked list
    void insert(int x) {
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to count triplets with sum equal to zero
    int count_triplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0; // Not enough elements to form triplets
        }

        int count = 0;
        Node* current = head->next;

        while (current->next != nullptr) {
            int sum = current->prev->data + current->data + current->next->data;
            if (sum == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }
};

int main() {
    int n;
    std::cin >> n;

    DoublyLinkedList myList;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        myList.insert(x);
    }

    int result = myList.count_triplets();
    std::cout << result << std::endl;

    return 0;
}

