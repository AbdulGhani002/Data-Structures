#ifndef FASTARRAYSTACK_H
#define FASTARRAYSTACK_H

#include <stdexcept>

class FastArrayStack
{
public:
    int *data;
    int size;
    int capacity;

    FastArrayStack();
    ~FastArrayStack();
    int get_capacity();
    int get_size();
    bool isEmpty();
    int get(int i);
    int set(int i, int x);
    int add(int i, int x);
    int remove(int i);
    void clear();
    void push(int x);
    int pop();

private:
    void resize();
};

FastArrayStack::FastArrayStack() : size(0), capacity(1)
{
    data = new int[capacity];
}

FastArrayStack::~FastArrayStack()
{
    delete[] data;
}

int FastArrayStack::get_capacity()
{
    return this->capacity;
}

int FastArrayStack::get_size()
{
    return this->size;
}

bool FastArrayStack::isEmpty()
{
    return this->size == 0;
}

int FastArrayStack::get(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

int FastArrayStack::set(int i, int x)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    int y = this->data[i];
    this->data[i] = x;
    return y;
}

void FastArrayStack::resize()
{
    if (this->size == 0)
    {
        return;
    }

    int new_capacity = this->capacity;

    if (this->size <= this->capacity / 4 && this->capacity > 1)
    {
        new_capacity = this->capacity / 2;
    }

    else if (this->size == this->capacity)
    {
        new_capacity = 2 * this->capacity;
    }

    if (new_capacity != this->capacity)
    {
        int *b = new int[new_capacity];
        for (int i = 0; i < this->size; i++)
        {
            b[i] = this->data[i];
        }
        delete[] this->data;
        this->data = b;
        this->capacity = new_capacity;
    }
}

int FastArrayStack::add(int i, int x)
{
    if (i < 0 || i > size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (this->size == this->capacity)
    {
        this->resize();
    }
    for (int j = this->size; j > i; j--)
    {
        this->data[j] = this->data[j - 1];
    }
    this->data[i] = x;
    this->size++;
    return x;
}

int FastArrayStack::remove(int i)
{
    if (i < 0 || i >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    int x = this->data[i];
    for (int j = i; j < size - 1; j++)
    {
        this->data[j] = this->data[j + 1];
    }
    this->size--;
    this->resize();
    return x;
}

void FastArrayStack::clear()
{
    this->size = 0;
}

void FastArrayStack::push(int x)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    this->data[this->size] = x;
    this->size++;
}

int FastArrayStack::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    int x = this->data[this->size - 1];
    this->size--;
    this->resize();
    return x;
}

#endif // FASTARRAYSTACK_H
