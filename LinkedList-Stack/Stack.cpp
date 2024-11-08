#include "Stack.h"

Stack::Stack(){
    top = nullptr;
}

void Stack::push(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void Stack::pop(){
    if(top == nullptr){
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void Stack::display(){
    Node* temp = top;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

bool Stack::isEmpty(){
    return top == nullptr;
}

int Stack::peek(){
    if(top == nullptr){
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return top->data;
}

int main(void){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    stack.pop();
    stack.display();
    std::cout << stack.peek() << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}