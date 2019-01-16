#pragma once

template<typename T>
class AutoPointer {

public:
    inline AutoPointer(T *obj)
            : m_member(obj) {};

    inline ~AutoPointer() {
        delete m_member;
    };

    inline AutoPointer(const AutoPointer &autoPointer) {
        m_member = new T(*autoPointer.m_member);
    };

    inline AutoPointer &operator=(const AutoPointer &autoPointer) {
        m_member = new T(*autoPointer.m_member);
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
};