#pragma once
#include "Node.h"

template <typename T>
class ListSearchTree
{

public:
    ListSearchTree();
    ~ListSearchTree();
    ListSearchTree(const ListSearchTree<T> &);
    ListSearchTree<T>& operator=(const ListSearchTree<T> &);
    
    bool insert(const T&, const int&);
    bool remove(const int&);
    T& getByIndex(const int&);

private:
    int m_size;
    Node* m_root;

    void clear();
    void copy(ListSearchTree<T> &);
    Node** find_node(const int&);
};

