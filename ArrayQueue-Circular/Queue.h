#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T> class Queue {
public:
  Queue(int size);
  ~Queue();
  void enqueue(T item);
  T dequeue();
  bool isEmpty();
  bool isFull();
  void print();

private:
  int front;
  int rear;
  int size;
  int count;
  T *queue;
};

template <class T> Queue<T>::Queue(int size) {
  this->size = size;
  queue = new T[size];
  front = 0;
  rear = 0;
  count = 0;
}

template <class T> Queue<T>::~Queue() { delete[] queue; }

template <class T> void Queue<T>::print() {
  if (isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }
  int i = front;
  for (int c = 0; c < count; c++) {
    std::cout << queue[i] << " ";
    i = (i + 1) % size;
  }
  std::cout << std::endl;
}

template <class T> void Queue<T>::enqueue(T item) {
  if (isFull()) {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  queue[rear] = item;
  rear = (rear + 1) % size;
  count++;
}

template <class T> T Queue<T>::dequeue() {
  if (isEmpty()) {
    std::cout << "Queue is empty" << std::endl;
    return T();
  }
  T item = queue[front];
  front = (front + 1) % size;
  count--;
  return item;
}

template <class T> bool Queue<T>::isEmpty() {
  return count == 0;
}

template <class T> bool Queue<T>::isFull() {
  return count == size;
}

#endif // QUEUE_H
