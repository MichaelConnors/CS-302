#include "BinaryNode.h"

//Default ctor
template<class T>
BinaryNode<T>::BinaryNode():l_node(NULL),r_node(NULL){}
//Parameterized ctor
template<class T>
BinaryNode<T>::BinaryNode(const T& data):l_node(NULL),r_node(NULL),m_data(data){}
//Copy ctor
template<class T>
BinaryNode<T>::BinaryNode(const BinaryNode& other):r_node(other.r_node),l_node(other.l_node),m_data(other.m_data){}
//Get method to retrieve data
template<class T>
const T& BinaryNode<T>::data()const{return m_data;}

