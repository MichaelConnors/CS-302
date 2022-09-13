#ifndef BinaryNode_H_INCLUDED
#define BinaryNode_H_INCLUDED

#include <iostream>

template<class T>class BinaryNode;
template<class T>class BinarySearchTree;
template<class T>class BinaryTree;

template<class T>
class BinaryNode{

  public:
      friend class BinarySearchTree<T>;
      friend class BinaryTree<T>;

    BinaryNode();
	BinaryNode(const T& data);
	BinaryNode(const BinaryNode<T>& other);

    const T& data()const;

  private:
    BinaryNode* r_node;
    BinaryNode* l_node;
    T m_data;
};

#endif // BinaryNode_H_INCLUDED
