#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue():f_ptr(NULL),b_ptr(NULL){}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other):f_ptr(other.f_ptr),b_ptr(other.b_ptr){
    Node<T>* tmp = other.f_ptr->m_next;
    for(Node<T>* curr = f_ptr->m_next;curr != b_ptr;curr = curr->m_next,tmp = tmp->m_next){
        curr = new Node<T>(tmp->data());
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue(){
    while(f_ptr != b_ptr){
    Node<T>* tmp_ptr = f_ptr;
    f_ptr = f_ptr->m_next;
    delete tmp_ptr;
    }
    delete f_ptr;
    delete b_ptr;

}

template<class T>
bool PriorityQueue<T>::enqueue(T& value){

   if(!isEmpty()){
        if(value < back()){
        Node<T>* curr = f_ptr;
        Node<T>* prev = NULL;
        while(value > curr->data() && curr != NULL){
            prev = curr;
            curr = curr->m_next;

        }
        if(curr != NULL && value == curr->data()){
            prev = curr;
            curr = curr->m_next;
        }

        Node<T>* tmp = new Node<T>(value,curr);
        prev->m_next = tmp;
        return true;
        }else{
            b_ptr->m_next = new Node<T>(value);
            b_ptr = b_ptr->m_next;
        }
   }else{
    f_ptr = new Node<T>(value);
    b_ptr = f_ptr;
    return true;
   }
   return false;
}

template<class T>
bool PriorityQueue<T>::dequeue(){
    if(!isEmpty()){
    Node<T>* tmp_ptr = f_ptr;
    f_ptr = f_ptr->m_next;
    delete tmp_ptr;
    return true;
    }
    return false;
}

template<class T>
const T& PriorityQueue<T>::front()const{
    if(!isEmpty()){
    return f_ptr->data();
    }else{
        std::cout << "The Queue is empty!" << std::endl;
    }
}

template<class T>
const T& PriorityQueue<T>::back()const{
    if(!isEmpty()){
        return b_ptr->data();
    }else{
        std::cout << "The Queue is empty"<< std::endl;
    }
}

template<class T>
const bool PriorityQueue<T>::isEmpty()const{
    if(f_ptr == NULL){
        return true;
    }
    return false;
}

template<class T>
const size_t PriorityQueue<T>::size()const{
    size_t qSize = 0;
    if(!isEmpty()){
    for(Node<T>* curr = f_ptr;curr != b_ptr;curr = curr->m_next){
        qSize++;
    }
    qSize++;
    }
    return qSize;
    }
