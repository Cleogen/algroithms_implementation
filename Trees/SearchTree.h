#pragma once

#include <queue>
#include "ostream"

template<typename T>
class SearchTree {
    template<typename E>
    friend std::ostream &operator<<(std::ostream &, const SearchTree<E> &);

public:
    SearchTree();

    ~SearchTree();

    SearchTree(const SearchTree<T> &);

    SearchTree<T> &operator=(const SearchTree<T> &);

    bool find(const int &);

    int count() const;

    bool empty() const;

    void elegant_insert(const int &);

    void insert(const int&);

    void remove(const int&);

    void elegant_remove(const int &);

private:
    struct Node {
        T m_info;
        Node *m_left;
        Node *m_right;

        Node(T info)
                : m_info(info), m_left(nullptr), m_right(nullptr) {}
    };

    Node* m_root;
    int m_size;

    Node **find_node(const int &);

    void copy(const SearchTree<T> &);

    void clear();
};
