#include "LinkedList.h"

//Default ctor
template<class T>
LinkedList<T>::LinkedList():m_front(NULL),m_back(NULL){}
//Parameterized ctor
template<class T>
LinkedList<T>::LinkedList(size_t size,const T& value):m_front(NULL),m_back(NULL){
    for(int i = 0; i < size;i++){
        add(value);
    }
}
//Copy ctor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other):m_front(other.m_front){
    m_front = new Node<T>(other.m_front->m_data);
    m_back = m_front;
    for(Node<T>* curr = other.m_front;curr != other.m_back;curr = curr->m_next){
        add(curr->m_data);
    }
}
//Dtor
template<class T>
LinkedList<T>::~LinkedList(){
    while(m_front != m_back){
        Node<T>* tmp_ptr = m_front;
        m_front = m_front->m_next;
        delete tmp_ptr;
        tmp_ptr = m_front;
    }
    delete m_front;
    delete m_back;
}
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs){

    m_front = rhs.m_front;
    m_back = m_front;
    for(Node<T>* curr = m_front;curr != rhs.m_back;curr = curr->m_next){
        m_back = new Node<T>(curr->m_data);
        m_back = m_back->m_next;
    }

}
//Returns the DataType of the first item in the list
template<class T>
T& LinkedList<T>::front(){
    if(m_front){
        return m_front->data();
    }
}
template<class T>
const T& LinkedList<T>::front()const{
    if(m_front){
        return m_front->data();
    }
}
//Returns the DataType of the last element of the list
template<class T>
T& LinkedList<T>::back(){
    if(m_front){
        return m_back->data();
    }
}
template<class T>
const T& LinkedList<T>::back()const{
    if(m_front){
        return m_back->data();
    }
}
//Adds an element at the back of the list
template<class T>
void LinkedList<T>::add(const T& value){
    if(empty()){
        m_front = new Node<T>(value);
        m_back = m_front;
    }else{
    m_back->m_next = new Node<T>(value);
    m_back = m_back->m_next;
    }
}
template<class T>
void LinkedList<T>::insertAfter(const T& target,const T& value){
    for(Node<T>* curr = m_front;curr != NULL;curr = curr->m_next){
        if(curr->data() == target){
                Node<T>* tmp_ptr = new Node<T>(value,curr->m_next);
                curr->m_next = tmp_ptr;
                std::cout << "Insertion successful!" << std::endl;
                break;
        }
    }
}
template<class T>
void LinkedList<T>::insertBefore(const T& target,const T& value){

    Node<T>* tmp_ptr = m_front->m_next;
    for(Node<T>* curr = m_front;curr != NULL; curr = curr->m_next){
    if(curr->data() == target && curr == m_front){
        Node<T>* new_ptr = new Node<T>(value,curr);
        m_front = new_ptr;
        break;
        }else if(tmp_ptr->data() == target){
            Node<T>* new_ptr = new Node<T>(value,tmp_ptr);
            curr->m_next = new_ptr;
            std::cout << "Insertion Successful!" << std::endl;
            break;
        }
        tmp_ptr = tmp_ptr->m_next;
    }
}
template<class T>
void LinkedList<T>::remove(const T& target){
    for(Node<T>* curr = m_front;curr != NULL;curr = curr->m_next){
        if(curr->m_next && curr->m_next->m_data == target){
            Node<T>* delNode_ptr = curr->m_next;
            curr->m_next = delNode_ptr->m_next;
            delete delNode_ptr;
            std::cout << "Successfully removed the item" << std::endl;
            break;
        }else if(curr->m_data == target && curr->m_next == m_back){
            Node<T>* delNode_ptr = curr;
            curr = delNode_ptr->m_next;
            delete delNode_ptr;
        }else if(m_front == curr && curr->data() == target){
            m_front = curr->m_next;
            delete curr;
        }
    }
}
//Clears the contents of the entire list
template<class T>
void LinkedList<T>::clear(){

    while(m_front != m_back){
        Node<T>* tmp_ptr = m_front;
        m_front = m_front->m_next;
        delete tmp_ptr;
        tmp_ptr = m_front;
    }
    delete m_back;
    m_front = NULL;
    m_back = NULL;
}
//Returns the size of the list
template<class T>
size_t LinkedList<T>::size()const{
    size_t count = 0;
    for(Node<T>* curr = m_front;curr != NULL;curr = curr->m_next,count++){}
    return count;
}
//Returns true if the list is empty, otherwise returns false
template<class T>
bool LinkedList<T>::empty()const{
    if(m_front == NULL){
        return true;
    }else{
        return false;
    }
}
//Outputs the contents of the list
template<class T>
void LinkedList<T>::serialize(std::ostream& os)const{

    for(Node<T>* curr = m_front;curr != NULL;curr = curr->m_next){
        os << " " << curr->m_data;
    }
}
//Uses the serialize function to display the
template<class T>
std::ostream& operator<<(std::ostream& os,const LinkedList<T>& LinkedList){
    os << "Data:";
    LinkedList.serialize(os);
    os << std::endl;
}
