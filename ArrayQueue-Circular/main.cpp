#include "Queue.h"

int main(void){
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    q.enqueue(8);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    return 0;
}