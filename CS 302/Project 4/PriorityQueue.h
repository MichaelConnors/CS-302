#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <iostream>
#include "Node.h"

template<class T>
class PriorityQueue{

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    ~PriorityQueue();

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

#endif // PRIORITYQUEUE_H_INCLUDED
