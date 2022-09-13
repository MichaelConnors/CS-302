#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Node.cpp"
template<class T> std::ostream& operator<<(std::ostream& os, const Stack<T>& defStack);

template<class T>
class Stack{
public:
    Stack();
    Stack(const Stack<T>& other);
    ~Stack();

    Stack<T>& operator=(const Stack<T>& rhs);
    void push(const T& value);
    T peek();
    void pop();
    void clear();
    bool isEmpty()const;
    bool isFull()const;

    void serialize(std::ostream& os)const;
    friend std::ostream& operator<< <>(std::ostream& os, const Stack<T>& stack);

private:
    Node<T>* m_head;
};

#endif // STACK_H_INCLUDED
