#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>
#include "BinaryNode.h"


template<class T>class BinarySearchTree;

template<class T>
class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T>& other);
    ~BinarySearchTree();

    bool add(const T& data);
    bool remove(const T& data);

    void inorder(BinaryNode<T>* node);
    void postorder(BinaryNode<T>* node);
    void preorder(BinaryNode<T>* node);

    BinaryNode<T>* getRoot();

    BinaryNode<T>* minNode(BinaryNode<T>* tmp_ptr);
    BinaryNode<T>* placeNode(BinaryNode<T>* sub_ptr,BinaryNode<T>* new_ptr);
    BinaryNode<T>* deleteNode(BinaryNode<T>* sub_ptr,const T& data);

    bool isEmpty();
    int getHeight(BinaryNode<T>* node);
    void clear(BinaryNode<T>* node);
private:
    BinaryNode<T>* root_ptr;

};


#endif // BINARYSEARCHTREE_H_INCLUDED
