//
// Created by ishkhan on 10/7/18.
//

#include <iostream>
#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
        : m_size(0), m_rear(nullptr), m_head(nullptr) {}

LinkedQueue::~LinkedQueue() {
    while (m_head != nullptr) {
        Node *temp = m_head->m_link;
        delete m_head;
        m_head = temp;
    }
}

LinkedQueue::LinkedQueue(const LinkedQueue &linkedQueue)
        : m_size(linkedQueue.m_size), m_head(nullptr), m_rear(nullptr) {
    if (!empty()) {
        m_head = new Node(linkedQueue.m_head->m_info);
        m_rear = linkedQueue.m_head->m_link;
        Node *temp = m_head;
        while (m_rear != nullptr) {
            temp->m_link = new Node(m_rear->m_info);
            temp = temp->m_link;
            m_rear = m_rear->m_link;
        }
    }
}

LinkedQueue &LinkedQueue::operator=(const LinkedQueue &linkedQueue) {
    if (this == &linkedQueue) {
        m_size = linkedQueue.m_size;
        if (!empty()) {
            m_head = new Node(linkedQueue.m_head->m_info);
            m_rear = linkedQueue.m_head->m_link;
            Node *temp = m_head;
            while (m_rear != nullptr) {
                temp->m_link = new Node(m_rear->m_info);
                temp = temp->m_link;
                m_rear = m_rear->m_link;
            }
        }
    }
    return *this;
}

int LinkedQueue::size() const {
    return m_size;
}

int &LinkedQueue::head() const {
    return m_head->m_info;
}

bool LinkedQueue::empty() const {
    return m_size == 0;
}

void LinkedQueue::pop() {
    if (!empty()) {
        Node *temp = m_head->m_link;
        delete m_head;
        m_head = temp;
        --m_size;
    } else {
        std::cout << "Queue is empty!\n";
    }
}

void LinkedQueue::push(const int &value) {
    Node *temp = m_rear;
    m_rear = new Node(value);
    ++m_size;
    (temp != nullptr) ? temp->m_link = m_rear : m_head = m_rear;
}

void LinkedQueue::display_queue() const {

}
