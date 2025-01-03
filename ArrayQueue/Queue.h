#include<iostream>
#ifndef QUEUE_H
#define QUEUE_H


template <class T>
class Queue{
 public:
  T* data;
  int size;
  int head;

  void init(int size){
        this->size = size;
    T data[this->size];
    this->head = -1;
  }
  void enque(T new_data){
    this->head++;
    this->data[head] = new_data;
  }

  T deque(){
    T removed = this->data[this->size];
    for(int i = 0;i<=this->head;i++){
      this->data[i] = this->data[i+1];
    }
    this->head--;
    return removed;
  }
  void display(){
    for(int i=0;i<=head;i++){
      std::cout<<this->data[i]<<" ";
    }
    std::cout<<std::endl;
  }
};

#endif // QUEUE_H
