#ifndef STACK_H
#define STACK_H

#include <iostream>

namespace data_structures {
  
template <class T>
class Stack {
protected:
    T* array;
    int head_index = -1;
    int size;

public:
    void init(int size);
    void display(void);
    T peek(void);
    int insert(T element);
    int pop();
};

template <class T>
void Stack<T>::init(int size) {
    this->size = size;
    this->array = new T[size];
}

template <class T>
void Stack<T>::display(void) {
    int temp = this->head_index;
    while (temp != -1) {
        std::cout << this->array[temp] << "  ";
        temp--;
    }
    std::cout << "\n";
}

template <class T>
T Stack<T>::peek(void) {
    return this->array[this->head_index];
}

template <class T>
int Stack<T>::insert(T element) {
    if (this->head_index < this->size - 1) {
        this->head_index++;
        this->array[this->head_index] = element;
        return this->head_index;
    }
    std::cout << "Stack overflow\n";
    return -1;
}

template <class T>
int Stack<T>::pop(void) {
    if (this->head_index >= 0) {
        this->array[this->head_index] = 0;
        this->head_index--;
        return this->head_index;
    }
    std::cout << "Stack underflow\n";
    return -1;
}

}

#endif // STACK_H
