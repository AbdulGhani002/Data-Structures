#include "Queue.h"
#include<iostream>

Queue::Queue(){
    front = rear = nullptr;
}

Queue::~Queue(){
    Node* p = front;
    while(front){
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::Enqueue(int x){
    Node* t = new Node;
    if(t == nullptr){
        std::cout << "Queue is full" << std::endl;
    }else{
        t->data = x;
        t->next = nullptr;
        if(front == nullptr){
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::Dequeue(){
    int x = -1;
    if(front == nullptr){
        std::cout << "Queue is empty" << std::endl;
    }else{
        Node* p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Queue::Display(){
    Node* p = front;
    while(p){
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(void){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    std::cout << q.Dequeue() << std::endl;
    q.Display();
    return 0;
}