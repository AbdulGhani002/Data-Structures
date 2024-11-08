#ifndef QUEUE_H

#define QUEUE_H

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        ~Queue();
        void Enqueue(int x);
        int Dequeue();
        void Display();
};

#endif