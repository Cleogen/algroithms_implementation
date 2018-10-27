//
// Created by ishkhan on 10/21/18.
//
#include "LinkedList.h"

std::ostream &operator << (std::ostream &out,const LinkedList &linkedList)
{
    out << "\n[";
    LinkedList::Node* temp = linkedList.m_head->m_link;
	for(int i = 0; i < linkedList.m_size; ++i)
    {
        out << temp->m_info << ", ";
        temp = temp->m_link;
    }
	out << "]\n";
	return out;
}

LinkedList::LinkedList()
: m_size(0)
, m_head(nullptr) {}

LinkedList::~LinkedList()
{
    Node* temp = m_head;
	Node* first = m_head;
	do {
		m_head = m_head->m_link;
		delete temp;
		temp = m_head;
	} while (temp != first);
}

LinkedList::LinkedList(const LinkedList &linkedList)
: m_size(linkedList.m_size)
, m_head(nullptr)
{
    if (m_size > 0){
        m_head = new Node(linkedList.m_head->m_info);
        m_head->m_link = m_head;
        Node* next = linkedList.m_head->m_link;
        Node* prev = m_head;
        for(int i = 1; i < m_size; ++i){
            prev->m_link = new Node(next->m_info);
            next = next->m_link;
            prev = prev->m_link;
        }
    }
}

LinkedList& LinkedList::operator=(const LinkedList &linkedList)
{
    if(this != &linkedList){

        clear();
        m_size = linkedList.m_size;

        if (m_size > 0){
            m_head = new Node(linkedList.m_head->m_info);
            m_head->m_link = m_head;
            Node* next = linkedList.m_head->m_link;
            Node* prev = m_head;
            for(int i = 1; i < m_size; ++i){
                prev->m_link = new Node(next->m_info);
                next = next->m_link;
                prev = prev->m_link;
            }
        }
    }
    return *this;
}

int &LinkedList::operator[](const int &index){
    return get_by_index(index)->m_info;
}

const int &LinkedList::operator[](const int &index) const{
    if (index >= m_size)
        throw std::out_of_range("Index out of range!");

    Node* temp = m_head->m_link;
    int m_index = (index >= 0) ? index : m_size + index;

    for(int i = 0; i != index; ++i){
        temp = temp->m_link;
    }
    return temp->m_info;
}

bool LinkedList::empty() const{
    return m_size == 0;
}

int LinkedList::size() const{
    return m_size;
}

void LinkedList::push(const int &value){
    Node* temp = new Node(value);

    if(m_head == nullptr){
        temp->m_link = temp;
    }
    else{
        temp->m_link = m_head->m_link;
        m_head->m_link = temp;
    }

    m_head = temp;
    ++m_size;
}

LinkedList::Node* LinkedList::get_by_index(const int& index){
    Node* temp = m_head->m_link;
    int m_index = (index >= 0) ? index : m_size + index;

    if (index >= m_size-1)
        throw std::out_of_range("Index out of range!");

    for(int i = 0; i != m_index; ++i){
        temp = temp->m_link;
    }
    return temp;
}

void LinkedList::push_at_index(const int &index, const int &value){
    Node* temp = get_by_index(index - 1);
    Node* next = new Node(value);
    next->m_link = temp->m_link;
    temp->m_link = next;
    ++m_size;
}

void LinkedList::push_all(const int* array, const int& size){
    for(int i = 0; i < size; ++i){
        push(array[i]);
    }
}

void LinkedList::pop(){
    if(!empty()){
        remove_at_index(-1);
    }
    else{
        throw std::out_of_range("List is Empty!");
    }
}

void LinkedList::remove_at_index(const int &index){
    Node* prev = get_by_index(index - 1);
    Node* temp = prev->m_link;
    prev->m_link = temp->m_link;
    if(m_head == temp)
        m_head = prev;
    delete temp;
    --m_size;
}

void LinkedList::remove_all(const int &value){
    Node* temp = m_head->m_link;
    for(int i = 0; i < m_size; ++i){
        if(temp->m_info == value){
            temp = temp->m_link;
            remove_at_index(i);
            --i;
        }
        else {
            temp = temp->m_link;
        }
    }
}

void LinkedList::clear(){
    Node* temp = m_head;
	Node* first = m_head;
	do {
		m_head = m_head->m_link;
		delete temp;
		temp = m_head;
	} while (temp != first);
    m_size = 0;
}
