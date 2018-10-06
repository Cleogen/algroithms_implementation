//
// Created by ishkhan on 10/6/18.
//

#include <iostream>
#include "LinkedStack.h"

LinkedStack::LinkedStack()
        : m_size(0), m_top(nullptr) {}

LinkedStack::~LinkedStack() {
    if (!empty()) {
        while (m_top->m_link != nullptr) {
            Node *temp = m_top->m_link;
            delete m_top;
            m_top = temp;
        }
    }
}

LinkedStack::LinkedStack(const LinkedStack &linkedStack)
        : m_size(linkedStack.m_size), m_top(nullptr) {
    if (!linkedStack.empty()) {
        m_top = new Node(linkedStack.m_top->m_info);
        bool sec = true;
        Node *cop = linkedStack.m_top->m_link;
        while (cop != nullptr) {
            Node *temp = new Node(cop->m_info);
            cop = cop->m_link;
            if (sec) {
                m_top->m_link = temp;
                sec = false;
            }
        }
    }
}

LinkedStack &LinkedStack::operator=(const LinkedStack &linkedStack) {
    if (this != &linkedStack) {
        m_size = linkedStack.m_size;
        if (!linkedStack.empty()) {
            m_top = new Node(linkedStack.m_top->m_info);
            bool sec = true;
            Node *cop = linkedStack.m_top->m_link;
            while (cop != nullptr) {
                Node *temp = new Node(cop->m_info);
                cop = cop->m_link;
                if (sec) {
                    m_top->m_link = temp;
                    sec = false;
                }
            }
        }
    }
    return *this;
}

int LinkedStack::top() {
    if (empty()) {
        std::cout << "\nLinked Stack is empty!\n";
        return 0;
    }
    return m_top->m_info;
}

int LinkedStack::size() const {
    return m_size;
}

bool LinkedStack::empty() const {
    return m_size == 0;
}

void LinkedStack::pop() {
    if (!empty()) {
        Node *temp = m_top->m_link;
        delete m_top;
        m_top = temp;
        --m_size;
    } else {
        std::cout << "\nLinked Stack is empty!\n";
    }
}

void LinkedStack::push(const int &value) {
    Node *temp = m_top;
    m_top = new Node(value);
    m_top->m_link = temp;
    ++m_size;
}

void LinkedStack::display_stack() const {

}
