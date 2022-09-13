#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Node.cpp"

template<class T>
class Queue{
public:
    Queue();
    Queue(const Queue& other);
    ~Queue();

    bool enqueue(T& value);
    bool dequeue();

    const T& front()const;
    const T& back()const;
    const bool isEmpty()const;
    const size_t size()const;

private:
    Node<T>* f_ptr;
    Node<T>* b_ptr;
};

#endif // QUEUE_H_INCLUDED
