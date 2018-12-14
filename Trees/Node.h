#pragma once

struct LTNode {
    LTNode *m_left;
    LTNode *m_right;

    LTNode()
        : m_left(nullptr)
        , m_right(nullptr)
    {}

    virtual ~LTNode() {}
};

struct Internal : LTNode
{
    int m_count;
    Internal(int count)
            : LTNode()
        , m_count(count)
    {}

    virtual ~Internal() {}
};

template <typename T>
struct External : LTNode
{
    T m_info;
    External(const T& info = T())
            : LTNode()
        , m_info(info)
    {}

    virtual ~External() {}
};

template<typename T>
struct STNode {
    T m_info;
    STNode *m_left;
    STNode *m_right;

    STNode(const T &info = new T())
            : m_info(info), m_left(nullptr), m_right(nullptr) {}
};