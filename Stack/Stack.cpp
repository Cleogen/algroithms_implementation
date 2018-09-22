//
// Created by ishkhan on 9/17/18.
//

#include <iostream>
#include "Stack.h"

Stack::Stack(int max_size)
        : m_maxsize(max_size), m_top(-1), m_location(nullptr) {
    m_location = new int[m_maxsize];
}

Stack::Stack(const Stack &stack)
        : m_maxsize(stack.m_maxsize), m_top(stack.m_top), m_location(nullptr) {
    m_location = new int[m_maxsize];
    for (int i = 0; i <= m_top; ++i) {
        m_location[i] = stack.m_location[i];
    }
}

Stack::~Stack() {
    delete[] m_location;
}

Stack &Stack::operator=(Stack stack) {
    if (&stack != this) {
        delete[] m_location;
        new Stack(stack);
    }
    return *this;
}

bool Stack::empty() const {
    return size() == 0;
}

bool Stack::full() const {
    return size() == m_maxsize;
}

int Stack::size() const {
    return m_top + 1;
}

int &Stack::top() {
    if (empty()) {
        std::cout << "Stack is empty!\n";
    }
    return m_location[m_top];
}

void Stack::pop() {
    if (!empty()) {
        --m_top;
    } else {
        std::cout << "Stack is empty!\n";
    }
}

void Stack::push(const int &x) {
    if (!full()) {
        m_location[++m_top] = x;
    } else {
        std::cout << "Stack is full!\n";
    }
}

void Stack::display_stack() {
    for (int i = 0; i <= m_top; ++i) {
        std::cout << " | " << m_location[i];
    }
    std::cout << "\n";
}