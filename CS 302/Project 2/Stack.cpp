#include "Stack.h"

template<class T>
Stack<T>::Stack():m_head(NULL){}

template<class T>
Stack<T>::Stack(const Stack<T>& other){
    for(Node<T>* curr = other.m_head; curr != NULL;curr = curr->m_next){
            push(curr->data());
    }
}

template<class T>
Stack<T>::~Stack(){
    for(Node<T>* curr = m_head->m_next;curr != NULL;curr = curr->m_next){
        delete m_head;
        m_head = curr;
    }
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs){
    if(!isEmpty()){
        clear();
    }else{
    m_head = rhs.m_head;
    for(Node<T>* curr = rhs.m_head->m_next;curr != NULL;curr = curr->m_next){
        push(curr->data());
        }
    }
}

template<class T>
void Stack<T>::push(const T& value){
    if(!(isFull())){
    if(isEmpty()){
        m_head = new Node<T>(value);
    }else{
        Node<T>* tmp_node = m_head;
        m_head = new Node<T>(value,tmp_node);


    }
    }
}

template<class T>
T Stack<T>::peek(){
    if(!isEmpty()){
    return m_head->m_data;
    }
}

template<class T>
void Stack<T>::pop(){
    if(!isEmpty()){
        Node<T>* tmp_ptr = m_head;
        m_head = m_head->m_next;
        delete tmp_ptr;
    }
}

template<class T>
void Stack<T>::clear(){
    for(Node<T>* curr = m_head->m_next;curr != NULL;curr = curr->m_next){
        delete m_head;
        m_head = curr;
    }
    m_head = NULL;
}

template<class T>
bool Stack<T>::isEmpty()const{
    if(m_head == NULL){
        return true;
    }else{
        return false;
    }
}

template<class T>
bool Stack<T>::isFull()const{
    return false;
}

template <class T>
void Stack<T>::serialize(std::ostream& os)const{
    for(Node<T>* curr = m_head;curr != NULL;curr = curr->m_next){
        os << curr->data() << " ";
    }
}

template<class T>
std::ostream& operator<<(std::ostream& os,const Stack<T>& defStack){
    defStack.serialize(os);
}
