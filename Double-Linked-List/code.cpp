#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {  
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {  
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFromFront() {
        if (head == nullptr) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) { 
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {  
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Forward display: ";
    list.displayForward();  

    cout << "Backward display: ";
    list.displayBackward();

    list.deleteFromFront();
    list.deleteFromEnd();

    cout << "After deletions - Forward display: ";
    list.displayForward(); 

    cout << "After deletions - Backward display: ";
    list.displayBackward();

    return 0;
}
