//
// Created by ishkhan on 10/21/18.
//
#include "LinkedList.h"

std::ostream &operator << (std::ostream &out,const LinkedList &linkedList)
{
    out << "\n[";
    LinkedList::Node* temp = linkedList.m_head;
	while(temp != nullptr)
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
{
    m_head = new Node(0);
}

LinkedList::~LinkedList()
{
    Node* temp = m_head;
    while(m_head != nullptr){
        delete m_head;
        temp = temp->m_link;
        m_head = temp;
    }
}

LinkedList::LinkedList(const LinkedList &linkedList)
: m_size(linkedList.m_size)
, m_head(nullptr)
{
    m_head = new Node(0);
    if (m_size != 0){
        Node* temp = linkedList.m_head->m_link;
        Node* next = new Node(temp->m_info);
        m_head = new Node(linkedList.m_head->m_info);
        m_head->m_link = next;
        while(temp != nullptr)
        {
            temp = temp->m_link;
            next->m_link = new Node(temp->m_info);
            next = next->m_link;
        }
    }
}

LinkedList &LinkedList::operator=(const LinkedList &linkedList)
{
    if(this != &linkedList){
        m_size = linkedList.m_size;
        m_head = new Node(0);
        if (m_size != 0){
            Node* temp = linkedList.m_head->m_link;
            Node* next = new Node(temp->m_info);
            m_head = new Node(linkedList.m_head->m_info);
            m_head->m_link = next;
            while(temp != nullptr)
            {
                temp = temp->m_link;
                next->m_link = new Node(temp->m_info);
                next = next->m_link;
            }
        }
    }
    return *this;
}

int &LinkedList::operator[](const int &index){
    Node* temp = m_head;
    for(int i = 0; i != index; ++i){
        temp = temp->m_link;
    }
    return temp->m_info;
}

const int &LinkedList::operator[](const int &index) const{
    Node* temp = m_head;
    for(int i = 0; i != index; ++i){
        temp = temp->m_link;
    }
    return temp->m_info;
}

void LinkedList::push(const int &value){
    ++m_size;
    m_head->m_link = new Node(value);
    m_head = m_head->m_link;
}

void LinkedList::push_at_index(const int &index, const int &value){
    
}

void LinkedList::push_all(const int* array){
    for(int i = 0; i < sizeof(array)/sizeof(int); ++i){
        push(array[i]);
    }
}

