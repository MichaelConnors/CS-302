#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

template<class T>class Node;
template<class T>class Stack;

template<class T>
class Node{

  public:
      friend class Stack<T>;

    Node();
	Node(const T& data, Node<T> *next = NULL);
	Node(const Node<T>& other);

    const T& data()const;

  private:
    Node * m_next;
    T m_data;
};

#endif // NODE_H_INCLUDED
