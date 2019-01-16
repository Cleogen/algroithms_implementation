#pragma once

#include <iostream>

template<typename T>
class SharedPointer {

public:

    inline SharedPointer(T *obj)
            : m_member(obj), m_counter(nullptr) {
        m_counter = new int(1);
    };

    inline ~SharedPointer() {
        if (*m_counter == 1) {
            delete m_counter;
            delete m_member;
        } else {
            --*m_counter;
        }
    };

    inline SharedPointer(const SharedPointer &sharedPointer)
            : m_member(sharedPointer.m_member), m_counter(sharedPointer.m_counter) {
        ++*m_counter;
    };

    inline SharedPointer &operator=(const SharedPointer &sharedPointer) {
        if (this != &sharedPointer) {
            delete this;
            m_member = sharedPointer.m_member;
            m_counter = sharedPointer.m_counter;
            ++*m_counter;
        }
        return *this;
    };

    inline T *operator->() {
        return m_member;
    };

    inline T &operator*() {
        return *m_member;
    };

private:
    T *m_member;
    int *m_counter;
};