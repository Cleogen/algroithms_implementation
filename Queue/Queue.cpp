//
// Created by ishkhan on 9/22/18.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(int maxsize)
        : m_maxsize(maxsize), m_front(-1), m_rear(-1), m_size(0), m_location(nullptr) {
    m_location = new int[m_maxsize];
}

Queue::Queue(const Queue &queue)
        : m_maxsize(queue.m_maxsize), m_front(queue.m_front), m_rear(queue.m_rear), m_size(queue.m_size),
          m_location(nullptr) {
    m_location = new int[m_maxsize];
    for (int i = 0; i < m_maxsize; ++i) {
        m_location[i] = queue.m_location[i];
    }
}

Queue::~Queue() {
    delete[] m_location;
}

Queue &Queue::operator=(const Queue &queue) {
    if (&queue != this) {
        delete[] m_location;
		m_maxsize = queue.m_maxsize;
		m_front = queue.m_front;
		m_rear = queue.m_rear;
		m_size = queue.m_size;
		m_location = new int[m_maxsize];
		for (int i = 0; i < m_maxsize; ++i) {
			m_location[i] = queue.m_location[i];
		}
    }
    return *this;
}

int Queue::update_pos(int m) const {
    return (m < m_maxsize - 1) ? m + 1 : 0;
}

bool Queue::empty() const {
    return m_size == 0;
}

bool Queue::full() const {
    return m_size == m_maxsize;
}

int Queue::size() const {
    return m_size;
}

int &Queue::front() {
    if (empty())
        std::cout << "Queue is empty!\n";
    return m_location[update_pos(m_front)];
}

void Queue::pop() {
    if (!empty()) {
        --m_size;
        m_front = update_pos(m_front);
    } else {
        std::cout << "Queue is empty!\n";
    }
}

void Queue::push(const int &x) {
    if (!full()) {
        ++m_size;
        m_rear = update_pos(m_rear);
        m_location[m_rear] = x;
    } else {
        std::cout << "Queue is full!\n";
    }
}

void Queue::display_queue() {
    int i = update_pos(m_front);
	for (size_t j = 0; j < m_size; ++j){
        std::cout << " | " << m_location[i];
        i = update_pos(i);
    }
    std::cout << "\n";
}
