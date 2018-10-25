//
// Created by ishkhan on 10/21/18.
//
#include "LinkedList.h"

std::ostream &operator << (std::ostream &out,const LinkedList &linkedList)
{
    out << "\n[";
    LinkedList::Node* temp = linkedList.m_head;
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
, m_head(nullptr)
{}

LinkedList::~LinkedList()
{
    Node* temp = m_head;
    while(m_head != nullptr){
        m_head = m_head->m_link;
        delete temp;
        temp = m_head;
    }
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

LinkedList &LinkedList::operator=(const LinkedList &linkedList)
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

LinkedList::Node& LinkedList::get_by_index(const int& index){
    Node* temp = m_head->m_link;
    int m_index = (index >= 0) ? index : m_size + index;

    for(int i = 0; i != index; ++i){
        temp = temp->m_link;
    }
    return *temp;
}

int &LinkedList::operator[](const int &index){
    return get_by_index(index).m_info;
}

const int &LinkedList::operator[](const int &index) const{
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
    ++m_size;
    Node* temp = new Node(value);
    temp->m_link = m_head->m_link;
    m_head->m_link = temp;
    m_head = temp;
}

void LinkedList::push_at_index(const int &index, const int &value){
    Node temp = get_by_index(index - 1);
    Node* next = new Node(value);
    next->m_link = temp.m_link;
    temp.m_link = next;
}

void LinkedList::push_all(const int* array){
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i){
        push(array[i]);
    }
}

void LinkedList::pop(){
    if(!empty()){
        --m_size;
        Node* temp = m_head->m_link;
        delete m_head;
        m_head = temp;
    }
}

void LinkedList::remove_at_index(const int &index){
    Node temp = get_by_index(index - 1);
    Node* next = temp.m_link->m_link;
    delete temp.m_link;
    temp.m_link = next;
}

void LinkedList::remove_all(const int &value){
    Node* temp = m_head;
    for(int i = 0; i < m_size; ++i){
        if(temp->m_info == value){
            remove_at_index(i);
        }
        temp = temp->m_link;
    }
}

void LinkedList::clear(){
    Node* t = m_head;
    while(m_head != nullptr){
        m_head = m_head->m_link;
        delete t;
        t = m_head;
    }
    m_size = 0;
}