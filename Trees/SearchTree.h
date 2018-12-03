#pragma once
#include "BTree.h"

class SearchTree
{

public:
    SearchTree();
    ~SearchTree();
    SearchTree(const SearchTree&);
    SearchTree& operator=(const SearchTree&);

    bool find(const int&) const;
    int count() const;
    bool empty() const;
    void insert(const int&);
    void remove(const int&);

private:
    Node* m_root;
    int m_size;

    void copy();
};
