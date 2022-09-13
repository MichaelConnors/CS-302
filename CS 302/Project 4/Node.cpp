#include "Node.h"
//Default ctor
template<class T>
Node<T>::Node():m_next(NULL){}
//Parameterized ctor
template<class T>
Node<T>::Node(const T& data, Node<T>* next):m_next(next),m_data(data){}
//Copy ctor
template<class T>
Node<T>::Node(const Node& other):m_next(other.m_next),m_data(other.m_data){}
//Get method to retrieve data
template<class T>
const T& Node<T>::data()const{return m_data;}

