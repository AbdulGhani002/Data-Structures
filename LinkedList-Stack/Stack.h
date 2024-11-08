#ifndef STACK_H

#define STACK_H

#include <iostream>

class Node{
public:
    int data;
    Node* next;

};

class Stack{
public:
    Node* top;
    Stack();
    void push(int data);
    void pop();
    void display();
    bool isEmpty();
    int peek();
};


#endif // STACK_H