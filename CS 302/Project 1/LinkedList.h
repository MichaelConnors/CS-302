#ifndef LinkedList_H_INCLUDED
#define LinkedList_H_INCLUDED

#include "Node.cpp"

template<class T>std::ostream& operator<<(std::ostream& os, const LinkedList<T>& nodeStack);

template<class T>
class LinkedList{

public:
    LinkedList();
    LinkedList(size_t size,const T& value);
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();

    LinkedList<T>& operator=(const LinkedList<T> &rhs);

    T& front();
    const T& front()const;

    T& back();
    const T& back()const;

    void add(const T& value);
    void insertAfter(const T & target, const T & value);
    void insertBefore(const T & target, const T & value);
    void remove(const T & target);

    size_t size()const;
    bool empty()const;
    void clear();
    void serialize(std::ostream& os)const;

    friend std::ostream& operator<< <>(std::ostream& os,const LinkedList<T>& LinkedList);

private:
    Node<T>* m_front;
    Node<T>* m_back;
};

#endif // LinkedList_H_INCLUDED
