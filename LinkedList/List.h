#ifndef LIST_H
#define LIST_H

#include <iostream>

class Node {
public:
  int data;
  Node* next_node;

  Node(int value) : data(value), next_node(nullptr) {}
};

class List {
public:
  Node* head;
  int size;

  List() : head(nullptr), size(0) {}

  void init(int data) {
    head = new Node(data);
    size = 1;
  }

  void insert_at_head(int data) {
    Node* new_node = new Node(data);
    new_node->next_node = head;
    head = new_node;
    size++;
  }

  void display() const {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << "  ";
      temp = temp->next_node;
    }
    std::cout << std::endl;
  }
};

#endif // LIST_H
