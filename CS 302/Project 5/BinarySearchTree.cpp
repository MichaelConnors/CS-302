#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree():root_ptr(NULL){}

template<class T>
BinarySearchTree<T>::~BinarySearchTree(){
    clear(root_ptr);
}
template<class T>
bool BinarySearchTree<T>::add(const T& data){
    BinaryNode<T>* new_ptr = new BinaryNode<T>(data);
    root_ptr = placeNode(root_ptr,new_ptr);
    return true;
}

template<class T>
bool BinarySearchTree<T>::remove(const T& data){
    deleteNode(root_ptr,data);
}
template<class T>
BinaryNode<T>* BinarySearchTree<T>::deleteNode(BinaryNode<T>* sub_ptr,const T& data){
    if(sub_ptr->data() > data){
        sub_ptr->l_node = deleteNode(sub_ptr->l_node,data);
    }else if(sub_ptr->data() < data){
        sub_ptr->r_node = deleteNode(sub_ptr->r_node,data);
    }else{
        if(sub_ptr->l_node == NULL){
            BinaryNode<T>* tmp_ptr = sub_ptr->r_node;
            delete sub_ptr;
            return tmp_ptr;
        }else if(sub_ptr->r_node == NULL){
            BinaryNode<T>* tmp_ptr = sub_ptr->l_node;
            delete sub_ptr;
            return tmp_ptr;
        }
        BinaryNode<T>* tmp_ptr = minNode(sub_ptr->r_node);

        sub_ptr->m_data = tmp_ptr->data();

        sub_ptr->r_node = deleteNode(sub_ptr->r_node,tmp_ptr->data());
    }
    return sub_ptr;
}

template<class T>
void BinarySearchTree<T>::inorder(BinaryNode<T>* node){

    if(node == NULL)
        return;

    inorder(node->l_node);
    std::cout << node->data() << " ";
    inorder(node->r_node);
}

template<class T>
void BinarySearchTree<T>::postorder(BinaryNode<T>* node){

    if(node == NULL)
        return;

        postorder(node->l_node);
        postorder(node->r_node);
        std::cout << node->m_data << " ";
}

template<class T>
void BinarySearchTree<T>::preorder(BinaryNode<T>* node){

    if(node == NULL)
        return;

        std::cout << node->m_data << " ";
        preorder(node->l_node);
        preorder(node->r_node);


}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* tmp_ptr){
    BinaryNode<T>* node = tmp_ptr;

    while(node != NULL && node->l_node != NULL){
        node = node->l_node;

        return node;
    }

}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::placeNode(BinaryNode<T>* sub_ptr,BinaryNode<T>* new_ptr){
    if(sub_ptr == NULL){
        return new_ptr;
    }else if(sub_ptr->data() > new_ptr->data()){
        BinaryNode<T>* tmp_ptr = placeNode(sub_ptr->l_node,new_ptr);
        sub_ptr->l_node = tmp_ptr;
    }else{
        BinaryNode<T>* tmp_ptr = placeNode(sub_ptr->r_node,new_ptr);
        sub_ptr->r_node = tmp_ptr;
    }

}

template<class T>
bool BinarySearchTree<T>::isEmpty(){
    if(root_ptr == NULL){
        return true;
    }
    return false;
}

template<class T>
int BinarySearchTree<T>::getHeight(BinaryNode<T>* node){
    if(root_ptr == NULL){
        return 0;
    }else{
        int l = getHeight(node->l_node);
        int r = getHeight(node->r_node);
    if(l > r){
        return (l+1);
    }else{
        return (r+1);
    }
    }
}

template<class T>
void BinarySearchTree<T>::clear(BinaryNode<T>* node){

    if(node == NULL)
    return;

    clear(node->l_node);
    clear(node->r_node);

    delete node;
}
template<class T>
BinaryNode<T>* BinarySearchTree<T>::getRoot(){
    return root_ptr;
}
