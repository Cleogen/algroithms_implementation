//
// Created by ishkhan on 9/22/18.
//

#include "Queue.h"

Queue::Queue(int maxsize)
        : m_maxsize(maxsize), m_front(-1), m_rear(-1), m_location(nullptr) {
    m_location = new int[m_maxsize];
}

Queue::Queue(const Queue &queue)
        : m_maxsize(queue.m_maxsize), m_front(queue.m_front), m_rear(queue.m_rear), m_location(nullptr) {
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
        new Queue(queue);
    }
    return *this;
}

bool Queue::empty() const {
    return false;
}

bool Queue::full() const {
    return false;
}

int Queue::size() const {
    return 0;
}

int &Queue::front() {
    return <#initializer#>;
}

void Queue::pop() {

}

void Queue::push(const int &) {

}

void Queue::display_queue() {

}
