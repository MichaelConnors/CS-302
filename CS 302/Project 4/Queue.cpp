#include "Queue.h"

template<class T>
Queue<T>::Queue():f_ptr(NULL),b_ptr(NULL){}

template<class T>
Queue<T>::Queue(const Queue& other):f_ptr(other.f_ptr),b_ptr(other.b_ptr){
    Node<T>* tmp = other.f_ptr->m_next;
    for(Node<T>* curr = f_ptr->m_next;curr != b_ptr;curr = curr->m_next,tmp = tmp->m_next){
        curr = new Node<T>(tmp->data());
    }
}


template<class T>
Queue<T>::~Queue(){
    while(f_ptr != b_ptr){
    Node<T>* tmp_ptr = f_ptr;
    f_ptr = f_ptr->m_next;
    delete tmp_ptr;
    }
    delete f_ptr;
    delete b_ptr;

}

template<class T>
bool Queue<T>::enqueue(T& value){
    if(isEmpty()){
        f_ptr = new Node<T>(value);
        b_ptr = f_ptr;
        return true;
    }else{
        b_ptr->m_next = new Node<T>(value);
        b_ptr = b_ptr->m_next;
        return true;
    }
    return false;
}
template<class T>
bool Queue<T>::dequeue(){
    if(!isEmpty()){
    Node<T>* tmp_ptr = f_ptr;
    f_ptr = f_ptr->m_next;
    delete tmp_ptr;
    return true;
    }
    return false;
}

template<class T>
const T& Queue<T>::front()const{
    if(!isEmpty()){
    return f_ptr->data();
    }else{
        std::cout << "The Queue is empty!" << std::endl;
    }
}

template<class T>
const T& Queue<T>::back()const{
    if(!isEmpty()){
        return b_ptr->data();
    }else{
        std::cout << "The Queue is empty"<< std::endl;
    }
}

template<class T>
const bool Queue<T>::isEmpty()const{
    if(f_ptr == NULL){
        return true;
    }
    return false;
}

template<class T>
const size_t Queue<T>::size()const{
    size_t qSize = 0;
    if(!isEmpty()){
    for(Node<T>* curr = f_ptr;curr != b_ptr;curr = curr->m_next){
        qSize++;
    }
    qSize++;
    }
    return qSize;
    }



