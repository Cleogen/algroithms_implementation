#pragma once

struct Node
{
    Node* m_left;
    Node* m_right;
    Node()
        : m_left(nullptr)
        , m_right(nullptr)
    {}

    virtual ~Node() {}
};

struct Internal : Node
{
    int m_count;
    Internal(int count)
        : Node()
        , m_count(count)
    {}

    virtual ~Internal() {}
};

template <typename T>
struct External : Node
{
    T m_info;
    External(const T& info = T())
        : Node()
        , m_info(info)
    {}

    virtual ~External() {}
};